#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int mod = 1e9+7;

int dp[100000][102];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int a[n];	for(int &x: a)	cin >> x;
	if(a[0] == 0) {
		for(int i = 1; i <= m; i++)
			dp[0][i] = 1;
	}
	else	dp[0][a[0]] = 1;
	for(int i = 1; i < n; i++)
	{
		if(a[i] == 0)
		{
			for(int j = 1; j <= m; j++)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
		}
		else
		dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % mod;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
		ans = (ans + dp[n - 1][i]) % mod;
	cout << ans;
}