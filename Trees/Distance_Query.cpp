#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
vector<pair<int, int>> adj[MAX];
int mn[MAX][18], mx[MAX][18], AN[MAX][18];
int tin[MAX], tout[MAX], height[MAX];
int l, timer;

void dfs(int u, int p, int h = 0) {
	tin[u] = ++timer;
	height[u] = h;
	for (int i = 1; 1 << i <= h; ++i) {
		mn[u][i] = min(mn[u][i - 1], mn[AN[u][i - 1]][i - 1]);
		mx[u][i] = max(mx[u][i - 1], mx[AN[u][i - 1]][i - 1]);
		AN[u][i] = AN[AN[u][i - 1]][i - 1];
	}

	for (auto [v, w]: adj[u])
	if(v != p) {
		mn[v][0] = w;
		mx[v][0] = w;
		AN[v][0] = u;
		dfs(v, u, h + 1);
	}

	tout[u] = ++timer;
}

bool is_ancestor(int u, int v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
	if (is_ancestor(u, v))	return u;
	if (is_ancestor(v, u))	return v;
	for (int i = l; i >= 0; --i) {
		if (!is_ancestor(AN[u][i], v))
			u = AN[u][i];
	}
	return AN[u][0];
}

void query(int u, int k, pair<int, int>& q) {
	int j = 0;
	while(k and u)
	{
		if(k & 1)
		{
			q = { min(q.first, mn[u][j]),
					max(q.second, mx[u][j]) };
			u = AN[u][j];
		}
		j++;
		k >>= 1;
	}
	return;
}
pair<int, int> query(int u, int v) {
	int l = lca(u, v);
	pair<int, int> p = {1 << 30, -(1 << 30)};
	query(u, height[u]-height[l], p);
	query(v, height[v]-height[l], p);
	return p;
}

int32_t main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	l = ceil(log2(n));
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs(0, 0);
	int q;	cin >> q;
	while(q--)
	{
		int u, v; cin >> u >> v; u--, v--;
		pair<int, int> p = query(u, v);
		cout << p.first << ' ' << p.second << '\n';
	}
}