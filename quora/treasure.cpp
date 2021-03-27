#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
int dp[1002][1002];
int ways[1002][1002];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	
	ways[1][1] = 1;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (s[i - 1][j - 1] == '1');
		if(s[i - 1][j - 1] == '1')
		{
			if(dp[i - 1][j] == dp[i][j] - 1)
				ways[i][j] += ways[i - 1][j];
			if(dp[i][j - 1] == dp[i][j] - 1)
				ways[i][j] += ways[i][j - 1];
		}
		else
		{
			if(dp[i - 1][j] == dp[i][j])
				ways[i][j] += ways[i - 1][j];
			if(dp[i][j - 1] == dp[i][j])
				ways[i][j] += ways[i][j - 1];
		}
		if(ways[i][j] >= mod)				ways[i][j] -= mod;
	}
	cout << dp[n][n] << ' ' << ways[n][n];
}