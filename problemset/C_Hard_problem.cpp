#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	string s[n], r[n];
	int c[n];
	for(auto &x: c)	cin >> x;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		r[i] = s[i];	
		reverse(r[i].begin(), r[i].end());
	}
	int dp[n + 1][2];
	dp[0][0] = 0, dp[0][1] = c[0];
	auto cmp = [&](string &s1, string& s2) {
		int m = s1.length(), n = s2.length();
		for(int i = 0; i < min(m, n); i++) {
			if(s1[i] != s2[i])
				return s1[i] < s2[i];
		}
		return m <= n;
	};
	for(int i = 1; i < n; i++) {
		dp[i][0] = dp[i][1] = 1e18;
		if(cmp(s[i - 1], s[i]))
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if(cmp(r[i - 1], s[i]))
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if(cmp(s[i - 1], r[i]))
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		if(cmp(r[i - 1], r[i]))
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
	}
	int ans = min(dp[n - 1][0], dp[n - 1][1]);
	if(ans == 1e18)
		ans = -1;
	cout << ans;
}