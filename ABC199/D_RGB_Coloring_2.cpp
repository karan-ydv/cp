#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vv adj;
	int n;
	vector<int> depth, col;
	vector<bool> vis;
	Graph(int v, int e)
	{
		n = v;
		adj.resize(v + 1);
		depth.resize(v + 1);
		col.resize(v + 1);
		vis.resize(v + 1);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	int dfs(int u = 1, int c = 0)
	{
		// cout << u << '\n';
		int ret = 1;
		col[u] = c;
		vis[u] = 1;
		for(int v: adj[u])
		if(depth[v] == depth[u] + 1 or depth[v] == 0)
		{
			depth[v] = depth[u] + 1;
			ret *= dfs(v, (c + 1) % 3) + dfs(v, (c + 2) % 3);
		}
		else if(col[v] == c)	ret = 0;
		// cout << u << " " << ret << '\n';
		col[u] = -1;
		return ret;
	}
	int solve()
	{
		int ans = 1;
		depth[1] = 1;
		for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			ans *= 3 * dfs(i);
		}
		return ans;
	}
};
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	Graph g(n, m);
	cout << g.solve();
}