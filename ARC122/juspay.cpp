#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    vector<vector<int>> children;
    vector<int> parent;
	vector<string> lockid;
	vector<int> lockedDescendents;
    vector<bool> islocked;
	unordered_map<string, int> mp;
	queue<int> locked;
	vector<int> tin, tout;

    int v;
    Graph(int n, int m)
    {
		v = n;
		children.resize(n);
		parent.resize(n);
		islocked.resize(n);
		lockedDescendents.resize(n);
		lockid.resize(n);
		tin.resize(n);
		tout.resize(n);

		string s; cin >> s; mp[s] = 0;
		queue<int> q; q.push(0);
		int cnt = 1;
		while(cnt < n)
		{
			int f = q.front();
			q.pop();
			for(int i = 0; i < m; i++, cnt++)
			{
				cin >> s;
				mp[s] = cnt;
				parent[cnt] = f;
				children[f].emplace_back(cnt);
				q.push(cnt);
			}
		}
		DFS();
    }
	void DFS(int u = 0)
	{
		static int timer = 0;
		tin[u] = ++timer;
		for(int v: children[u])
			DFS(v);
		tout[u] = ++timer;
	}
    bool lock(string &node, string& uid)
    {
		int n = mp[node];
        if(islocked[n] or lockedDescendents[n])
			return false;
        while(n)
        {
            n = parent[n];
            if(islocked[n])
				return false;
        }
		n = mp[node];
		lockid[n] = uid;
		islocked[n] = true;
		locked.push(n);
        while(n)
        {
            n = parent[n];
			lockedDescendents[n] += 1;
        }
        return true;
    }
    bool unlock(string &node, string& uid)
    {
		int n = mp[node];
		if(!islocked[n] or lockid[n] != uid)
			return false;
		islocked[n] = false;
		for(int p = n; p; )
		{
			p = parent[p];
			lockedDescendents[p]--;
		}
		return true;
    }
	bool isAncestor(int u, int v)
	{
		return tin[u] <= tin[v] and tout[u] >= tout[v];
	}
	bool upgradeLock(string& node, string& uid)
	{
		int n = mp[node];
		if(islocked[n] or lockedDescendents[n] == 0)
			return false;

		for(int p = n; p; )
		{
			p = parent[p];
			if(islocked[p])	return false;
		}

		vector<int> child, nchild;
		queue<int> q;

		bool flag = true;
		while(!locked.empty())
		{
			int x = locked.front();
			locked.pop();

			if(islocked[x])
			{
				if(isAncestor(n, x))
				{
					if(lockid[x] != uid)
					{
						flag = false;
						goto outside;
					}
					child.emplace_back(x);
				}
				else nchild.emplace_back(x);
			}
		}

		outside:
		for(int x: nchild)
			locked.push(x);
		
		if(!flag)
		{
			for(int x: child)
				locked.push(x);
			return false;
		}

		for(int x: child)
			islocked[x] = false;

		lockid[n] = uid;
		islocked[n] = true;
		int x = lockedDescendents[n];
		lockedDescendents[n] = 0;
		for(int p = n; p; )
		{
			p = parent[p];
			lockedDescendents[p] += 1 - x;
		}
		return true;
	}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;	cin >> n >> m >> q;
	Graph g(n, m);
	while(q--)
	{
		int op;
		string node, uid;
		cin >> op >> node >> uid;
		bool ans;
		if(op == 1)
			ans = g.lock(node, uid);
		else if(op == 2)
			ans = g.unlock(node, uid);
		else
			ans = g.upgradeLock(node, uid);
		cout << (ans ? "true" : "false") << '\n';
	}
}