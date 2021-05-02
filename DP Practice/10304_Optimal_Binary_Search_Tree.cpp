#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	
	while(cin >> n)	
	{
		int f[n];	for(int &x: f)	cin >> x;
		int A[n + 1] = {0};
		partial_sum(f, f + n, A + 1);
		int dp[n + 1][n + 1];
		for(int i = 1; i <= n; i++)	dp[i][i] = 0;
		for(int i = 1; i <= n; i++)
		for(int j = 1; j + i <= n; j++)
		{
			dp[j][j + i] = 1 << 30;
			for(int k = j; k <= j + i; k++)
			{
				int x = 0;
				if(k > j)		x += dp[j][k - 1] + (A[k - 1] - A[j - 1]);
				if(k < j + i)	x += dp[k + 1][j + i] + (A[j  + i] - A[k]);
				dp[j][j + i] = min(dp[j][j + i], x);
			}
		}
		cout << dp[1][n] << '\n';
	}
}