#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	vector<int> dp(m + 1, 1);
	// for(int i = 1; i <= m; i++) {
	// 	dp[i] = dp[i - 1] + m / i;
	// }

	int ans = 1;
	for(int _ = 1; _ <= n; _++) 
	{
		for(int i = 2; i <= m; i++) 
		{
			cout << dp[i] << " \n"[i == m];
			ans = (ans + dp[i]) % mod;
			for(int j = 2; i * j <= m; j++)
				dp[i] = (dp[i] + dp[i * j]) % mod;
		}
	}
	cout << ans;
}