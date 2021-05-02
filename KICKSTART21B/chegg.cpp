#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vv adj;
	vector<int> children;
	int n;
	Graph(int v, int e)
	{
		n = v;
		adj.resize(v + 1);
		children.resize(v + 1);
		for(int i = 1; i <= v; i++)
		{
			int w, l, r;
			cin >> w >> l >> r;
			children[i] = w;
			if(l != 0)
			{
				adj[i].emplace_back(l);
				adj[l].emplace_back(i);
			}
			if(r != 0)
			{
				adj[i].emplace_back(r);
				adj[r].emplace_back(i);
			}
		}
	}
	int DFS(int u = 0, int p = -1, int h = 0)
	{
		int c = children[u] * h;
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
	int n;	cin >> n;
	Graph g(n, n);
	int mintime = 2e9;
	for(int i = 1; i <= n; i++) {
		mintime = min(mintime, g.DFS(i, -1));
	}
	cout << mintime;
}