#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		string a, b;	cin >> a >> b;

		int n = a.length();	a = '!' + a;
		int m = b.length();	b = '!' + b;

		int dp[n + 1][m + 1];
		for(int i = 0; i <= n; i++)	dp[i][0] = i;
		for(int i = 0; i <= m; i++)	dp[0][i] = i;

		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + (a[i] != b[j]);
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			// cout << dp[i][j] << " \n"[j == m];
		}
		cout << dp[n][m] << '\n';
	}
}