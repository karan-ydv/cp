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
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		vector<int> v(n), w(n);
		for(int i = 0; i < n; i++)
			cin >> v[i] >> w[i];
		int ans = 0, g;
		cin >> g;
		while(g--)
		{
			int x;	cin >> x;
			ans += knapsack(v, w, x);
		}
		cout << ans << '\n';
	}
}