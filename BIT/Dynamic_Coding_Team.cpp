#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[2][n], dp[2][n];
	for(int i: {0, 1})	for(int& x:	a[i])	cin >> x;
			dp[0][0] = a[0][0];
	dp[1][0] = a[1][0];
	for(int i = 1; i < n; i++)
	{
		dp[0][i] = max(a[0][i] + dp[1][i - 1], dp[0][i- 1]);
		dp[1][i] = max(a[1][i] + dp[0][i - 1], dp[1][i- 1]);
	}
	int ans = max(dp[0][n - 1], dp[1][n - 1]);
	cout << ans << '\n';
}