#include <bits/stdc++.h>
using namespace std;

struct LCA {
	int l, timer;
	vector<vector<int>> AN;
	vector<int> tin, tout;

	LCA(vector<vector<int>>& adj) {
		int n = adj.size();
		l = ceil(log2(n));
		AN.assign(n, vector<int>(l + 1));
		tin.resize(n);
		tout.resize(n);
		dfs(adj, 0, 0);
	}
	void dfs(vector<vector<int>>& adj, int u, int p) {
		tin[u] = ++timer;
		for (int i = 1; i <= l; ++i) {
			AN[u][i] = AN[AN[u][i - 1]][i - 1];
		}

		for (auto v: adj[u])
		if (v != p) {
			AN[v][0] = u;
			dfs(adj, v, u);
		}
		tout[u] = ++timer;
	}

	bool is_ancestor(int u, int v)
	{
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	int lca(int u, int v)
	{
		if (is_ancestor(u, v))	return u + 1;
		if (is_ancestor(v, u))	return v + 1;
		for (int i = l; i >= 0; --i) {
			if (!is_ancestor(AN[u][i], v))
				u = AN[u][i];
		}
		return AN[u][0] + 1;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	int T = t;
	while(t--)
	{
		cout << "Case " << T - t << ": \n";
		int n;	cin >> n;
		vector<vector<int>> adj(n);
		for(int i = 0; i < n; i++) {
			int m, x;	cin >> m;
			for(int j = 0; j < m; j++)
				cin >> x, adj[i].push_back(x-1);
		}
		LCA tree(adj);
		int q;	cin >> q;
		while(q--)
		{
			int v, w;	cin >> v >> w;
			cout << tree.lca(--v, --w) << '\n';
		}
	}
}