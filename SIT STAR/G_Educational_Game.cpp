#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[128][128];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	string s;	cin >> n >> s;
	int m = s.length();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int j = 128 - i;
		dp[i][j] = 1;
		for(int k = 1; k < m; k++) {
			dp[i][j + k] = dp[i - 1][j + k] + dp[i][j + k - 1];
		}
		// cout << dp[i][j + m - 1] << ' ' ;
		ans += dp[i][j + m - 1];
		if(dp[i][j + m - 1] == dp[i - 1][j + m]) {
			ans += dp[i - 1][j + m] * (n - i);
			break;
		}
	}
	cout << ans << '\n';
}