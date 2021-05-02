#include <bits/stdc++.h>
#define int int64_t
using namespace std;


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int ans;
		cout << "Case #" << _ << ": ";
		int n;	string s;
		cin >> n >> s;
		s = s[0] + s;
		int dp[n + 1] = {0};
		for(int i = 1; i <= n; i++)
		{
			if(s[i - 1] < s[i])
			dp[i] = dp[i - 1] + 1;
			else
			dp[i] = 1;
			cout << dp[i] << ' ';
		}
		cout << '\n';
	}
}