#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < 2001; i++)
		dp[i][0] = dp[0][i] = i;
	int t;	cin >> t;
	cin.get();
	while(t--)
	{
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		
		int n = s1.length();
		int m = s2.length();

		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + (s1[i - 1] != s2[i - j]);
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
		}
		cout << dp[n][m] << '\n';
	}
}