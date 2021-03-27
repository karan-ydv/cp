#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[6][50001];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int t[m + 1][n + 1];

	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
	{
		cin >> t[j][i];
	}
	
	for(int i = 1; i <= m; i++)
	for(int j = 1; j <= n; j++)
	{
		dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + t[i][j];
	}

	for(int i = 1; i <= n; i++)
		cout << dp[m][i] << ' ';
}