#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef pair<int, int> pii;
	typedef int item;
	typedef vector<vector<item>> vv;
	vector<int> color;
	vector<pii> edges;
	vv adj;
	int n, curr_color;
	bool flag;
	Graph(int v, int e) {
		n = v;
		adj.resize(v);
		color.resize(v);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			u--, v--;
			edges.emplace_back(u, v);
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		for(int &c: color)	cin >> c;
	}
	void dfs2(int u, int p)
	{
		flag &= (color[u] == curr_color);
		for(auto v: adj[u])
		if(v != p)	dfs2(v, u);
	}
	bool DFS(int u)
	{
		flag = true;
		for(auto v: adj[u]) {
			curr_color = color[v];
			dfs2(v, -1);
		}
		return flag;
	}
	void solve()
	{
		bool flag = true;
		int U, V;
		for(auto [u, v]: edges) {
			if(color[u] != color[v])
			{
				flag = false;
				U = u, V = v;
				break;
			}
		}
		if(flag)	return cout << "YES\n1", void();
		if(DFS(U))	return cout << "YES\n" << U + 1, void();
		if(DFS(V))	return cout << "YES\n" << V + 1, void();
		cout << "NO";
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	Graph g(n, n - 1);
	g.solve();
}