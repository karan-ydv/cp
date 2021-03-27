#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x;
		vector<int> dp(n, -1);
		function<int (int)> f = [&](int i) {
			if(i >= n)	return 0LL;
			if(dp[i] != -1)	return dp[i];
			return dp[i] = a[i] + f(i + a[i]);
		};
		int ans = -1;
		for(int i = 0; i < n; i++)
			ans = max(ans, f(i));
		cout << ans << '\n';
	}
}