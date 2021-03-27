#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vv dp;
	int n;
	Graph(int v, int e) {
		n = v;
		dp.resize(v + 1, vector<int>(v + 1, 1LL << 60));
		while(e--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			dp[u][v] = dp[v][u] = min(w, dp[u][v]);
		}
		for(int i = 1; i <= n; i++) dp[i][i] = 0;
	}
	void FloydWarshall()
	{
		for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	}
	int query(int u, int v) {
		if(dp[u][v] == 1LL << 60)
			return -1;
		return dp[u][v];
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;	cin >> n >> m >> q;
	Graph g(n, m);
	g.FloydWarshall();
	while(q--) {
		int u, v;	cin >> u >> v;
		cout << g.query(u, v) << '\n';
	}
}