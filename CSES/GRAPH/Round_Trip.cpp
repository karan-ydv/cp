#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vv adj;
	vector<string> grid;
	vector<bool> visited;
	vector<int> parent;
	int n, m, cycle_beg, cycle_end;
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
	bool DFS(int u, int p)
	{
		visited[u] = 1;
		for(auto v: adj[u]) {
			if(v == p)	continue;
			parent[v] = u;
			if(visited[v]) {
				cycle_beg = u;
				cycle_end = v;
				return true;
			}
			if(DFS(v, u))	return true;
		}
		return false;
	}
	void solve()
	{
		cycle_beg = cycle_end = -1;
		for(int i = 1; i <= n; i++) {
			if(!visited[i] and DFS(i, -1))	break;
		}
		if(cycle_beg == -1)
			return cout << "IMPOSSIBLE\n", void();
		
		int v = cycle_beg;
		vector<int> cycle;
		while(1)
		{
			cycle.emplace_back(v);
			if(v == cycle_end)	break;
			v = parent[v];
		}
		cycle.emplace_back(cycle_beg);
		cout << cycle.size() << '\n';
		for(auto x: cycle)	cout << x << ' ';
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