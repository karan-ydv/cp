#include <bits/stdc++.h>
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vv adj;
	vector<string> grid;
	vector<bool> visited;
	vector<int> parent;
	int n, m;
	Graph(int v, int e) {
		n = v, m = e;
		adj.resize(v + 1);
		visited.resize(n + 1);
		parent.resize(n + 1, -1);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	void BFS(int beg, int end)
	{
		queue<int> q;
		q.push(beg);
		visited[beg] = 1;
		while(!q.empty())
		{
			auto u = q.front();
			q.pop();
			for(auto v: adj[u])
			{
				if(visited[v])	continue;
				parent[v] = u;
				if(v == end)	return;
				visited[v] = 1;
				q.push(v);
			}
		}
	}
	void solve() {

		BFS(1, n);
		if(parent[n] == -1)
			return cout << "IMPOSSIBLE", void();
		vector<int> v;
		int x = n;
		while(x != -1) {
			v.emplace_back(x);
			x = parent[x];
		}
		reverse(v.begin(), v.end());
		cout << v.size() << '\n';
		for(int u: v)	cout << u << ' ';
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	Graph g(n, m);
	g.solve();
}