#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++)
	{
		cout << "Case " << _ << ": ";
		int n;	cin >> n;
		if(n == 0)
		{
			cout << "0\n";
			continue;
		}
		int a[n];	for(int &x: a)	cin >> x;
		if(n == 1)
		{
			cout << a[0] << '\n';
			continue;
		}
		int dp[n];
		dp[0] = a[0];
		dp[1] = max(a[1], a[0]);
		for(int i = 2; i < n; i++)
			dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
		
		cout << dp[n - 1] << '\n';
	}
}