#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int dp[n], a[n];
	double d;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> d;
	
	dp[0] = 1;
	for(int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		if(a[j] <= a[i])
			dp[i] = max(dp[i], dp[j] + 1);
	}
	int ans = n - *max_element(dp, dp + n);
	cout << ans;
}