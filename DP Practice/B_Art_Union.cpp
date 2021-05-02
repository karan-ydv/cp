#include <bits/stdc++.h>
using namespace std;

const int M = 5e4+5;
const int N = 10;
int t[M][N], dp[M][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m, n;	cin >> m >> n;

	for(int i = 1; i <= m; i++)
	for(int j = 1; j <= n; j++)
		cin >> t[i][j];
	
	for(int i = 1; i <= m; i++)
	for(int j = 1; j <= n; j++)
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + t[i][j];
	
	for(int i = 1; i <= m; i++)
		cout << dp[i][n] << ' ';
}