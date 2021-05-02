#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 505, K = 11;
int dp[K][N][N], H[N][N], V[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;	cin >> n >> m >> k;
	if(k & 1)
	{
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << "-1" << " \n"[j == m - 1];
		return 0;
	}

	for(int i = 1; i <= n; i++)	for(int j = 1; j < m; j++)	cin >> H[i][j];
	for(int i = 1; i < n; i++)	for(int j = 1; j <= m; j++)	cin >> V[i][j];

	k >>= 1;
	for(int d = 1; d <= k; d++)
	{
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int &x = dp[d][i][j];	x = 2e9;
			if(j > 1)	x = min(x, dp[d - 1][i][j - 1] + H[i][j - 1]);
			if(j < m)	x = min(x, dp[d - 1][i][j + 1] + H[i][j]);
			if(i > 1)	x = min(x, dp[d - 1][i - 1][j] + V[i - 1][j]);
			if(i < n)	x = min(x, dp[d - 1][i + 1][j] + V[i][j]);
		}
	}
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
	{
		cout << 2 * dp[k][i][j] << " \n"[j == m];
	}
}