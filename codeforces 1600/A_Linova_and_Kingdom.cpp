#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef int item;
	typedef pair<int, int> pii;
	typedef vector<vector<item>> vv;
	priority_queue<pii, vector<pii>> q;
	vector<int> v;
	vv adj;
	int n, c, k;
	Graph(int v, int k) {
		n = v;	c = 0;
		this -> k = k;
		adj.resize(v + 1);
		this -> v.resize(v);
		for(int i = 1; i < v; i++)
		{
			int u, v;	cin >> u >> v;
			u--, v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	int DFS(int u, int p, int h)
	{
		int c = 1;
		for(auto v: adj[u])
		if(v != p)
		{
			c += DFS(v, u, h + 1);
		}
		v[u] = c - h;
		return c;
	}
	void solve()
	{
		DFS(0, -1, 1);
		nth_element(v.begin(), v.begin() + k, v.end());
		int ans = accumulate(v.begin() + k, v.end(), 0LL);
		cout << ans << '\n';
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	Graph g(n, k);
	g.solve();
}