#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &V, vector<int> &W, int X)
{
	int n = V.size();
	vector<vector<int>> dp(n + 1, vector<int>(X + 1));
	for(int i = 1; i <= n; i++)
	{
		int v = V[i - 1], w = W[i - 1];
		for(int j = 0; j <= X; j++)
		if(j < w)
			dp[i][j] = dp[i - 1][j];
		else
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
	}
	return dp[n][X];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, c0, d0;
	cin >> n >> m >> c0 >> d0;
	int a[m], b[m], c[m], d[m];
	vector<int> v, w;
	for(int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		for(int j = 0; j < a[i] / b[i]; j++)
			v.emplace_back(d[i]), w.emplace_back(c[i]);
	}
	for(int i = 0; i < n / c0; i++) {
		v.emplace_back(d0), w.emplace_back(c0);
	}
	cout << knapsack(v, w, n);
}