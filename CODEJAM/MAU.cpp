#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		string s;
		int ans = 0, x, y, n;
		cin >> x >> y >> s;
		n = s.length();

		int dp[n][2];

		dp[0][0] = dp[0][1] = 0;
		if(s[0] == 'C')	dp[0][1] = 2e9;
		if(s[0] == 'J')	dp[0][0] = 2e9;

		for(int i = 1; i < n; i++) {
			if(s[i] == '?')
			{
				dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
				dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
			}
			else if(s[i] == 'C')
			{
				dp[i][1] = 2e9;
				dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
			}
			else
			{
				dp[i][0] = 2e9;
				dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
			}
		}
		ans = min(dp[n - 1][0], dp[n - 1][1]);
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}