#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1LL << 60;
struct Graph {
	vector<tuple<int, int, int>> E;
	vector<int> dp;
	int n;
	Graph(int v, int e) {
		n = v;
		dp.resize(v + 1, -INF);
		E.resize(e);
		for(int i = 0; i < e; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			E[i] = {u, v, w};
		}
	}
	void BellmanFord(int x, int y)
	{
		dp[x] = 0;
		for(int i = 1; i < n; i++)
		for(auto [u, v, w]: E) {
			if(dp[u] != -INF)
			dp[v] = max(dp[v], dp[u] + w);
		}
		for(int i = 1; i < n; i++)
		for(auto [u, v, w]: E) {
			if(dp[u] != -INF)
			if(dp[u] + w > dp[v])
				dp[v] = INF;
		}
		if(dp[y] == INF) dp[y] = -1;
		cout << dp[y];
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	Graph g(n, m);
	g.BellmanFord(1, n);
}