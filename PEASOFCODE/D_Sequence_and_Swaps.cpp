#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vector<int> color;
	vv adj;
	int n;
	Graph(int v, int e) {
		n = v;
		adj.resize(v);
		color.resize(v);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			u--, v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		for(int &c: color)	cin >> c;
	}
	int DFS(int u = 0, int p = -1, int h = 0)
	{
		int c = 0;
		for(auto v: adj[u])
		if(v != p)
		{
			c += DFS(v, u, h + 1);
		}
		return c;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, x;	cin >> n >> x;
		for(int &x: a)	cin >> x;
		vector<vector<int>> dp(n, vector<int>(501, 1 << 30));
		
		
	}
}