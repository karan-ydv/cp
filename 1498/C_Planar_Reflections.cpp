#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
const int N = 1005;
int dp[N][N][2];
int n, k;

int fun(int i, int j, int m)
{
	if(i == 0)	return 0ll;
	if(j == 0)	return 1ll;
	if(dp[i][j][m] != -1)	return dp[i][j][m];
	return dp[i][j][m] = (fun(i, j - 1, m) + fun(i - 1, n - j, 1 - m)) % mod;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 0; i <= k; i++)
		for(int j = 0; j <= n; j++)
			dp[i][j][0] = dp[i][j][1] = -1;

		cout << fun(k, n, 1) << '\n';
	}
}