// With threadsafe lock method and all other methods removed

#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    vector<vector<int>> children;
    vector<int> parent;
	vector<string> lockid;
	vector<int> lockedDescendents;
    vector<int> islocked;
	unordered_map<string, int> mp;
	vector<int> locked;
	vector<int> tin, tout;

    int v;
    Graph(int n, int m)
    {
		v = n;
		lockedDescendents.resize(n);
		children.resize(n);
		islocked.resize(n);
		parent.resize(n);
		lockid.resize(n);
		tout.resize(n);
		tin.resize(n);

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
    }
    bool lock(string &node)
    {
    	int n = mp[node];

        // if two threads come here simultaneously both shall fail
        // otherwise the later one shall fail
        islocked[n] += 1;
        if(islocked[n] > 1)
        {
            islocked[n] -= 1;
    		return false;
        }
        if(lockedDescendents[n] > 0)
        {
            islocked[n] = 0;
    		return false;
        }
        
        stack<int> stack;
        for(int p = parent[n]; p != 0; p = parent[p])
        {
            lockedDescendents[p] += 1;
            stack.push(p);
            if(islocked[p])
            {
                islocked[n] = 0;
                while(!stack.empty())
                {
                    int x = stack.top();
                    stack.pop();
                    lockedDescendents[x] -= 1;
                }
    			return false;
            }
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
		string node;
		cin >> node;
		bool ans = g.lock(node);
		cout << (ans ? "true" : "false") << '\n';
	}
}