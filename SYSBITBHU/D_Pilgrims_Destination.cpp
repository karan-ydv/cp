#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph
{
	typedef pair<int, int> item;
	typedef vector<vector<item>> vv;
	vv adj;
	int n;
	vector<int> cst;
	Graph(int v, int e)
	{
		n = v;
		adj.resize(v);
		while(e--)
		{
			int u, v, k;
			cin >> u >> v >> k;
			u--, v--;
			adj[u].emplace_back(v, k);
			adj[v].emplace_back(u, k);
		}
	}
	void DFS(int u = 0, int p = -1, int d = 1, int c = 0)
	{
		if(adj[u].size() == 1 and u != 0)
		{
			cst.emplace_back(c);
		}
		for(auto [v, k]: adj[u])
		if(v != p)
		{
			DFS(v, u, d + 1, c + d * k);
		}
	}
	int solve(vector<int> &v)
	{
		DFS();
		sort(cst.begin(), cst.end());
		// for(int c: cst)	cout << c << ' ';	cout << '\n';
		// for(int x: v)	cout << x << ' ';	cout << '\n';
		int m = v.size(), i = 0, ans = 0;
		for(int x: cst)
		{
			while(i < m and v[i] < x) i++;
			if(i == m)	break;
			ans++, i++;
		}
		return ans;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, m;	cin >> n >> m;
		vector<int> E(m);
		for(int &x: E)	cin >> x;
		Graph g(n, n - 1);
		sort(E.begin(), E.end());
		cout << g.solve(E) << '\n';
	}
}