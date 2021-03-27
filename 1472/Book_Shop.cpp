#include <bits/stdc++.h>
using namespace std;

int dp[1000][100001];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;	cin >> n >> x;
	int h[n];	for(int& v: h)	cin >> v;
	int s[n];	for(int& v: s)	cin >> v;

	for(int i = h[0]; i <= x; i++)
		dp[0][i] = s[0];
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < h[i]; j++)
			dp[i][j] = dp[i - 1][j];
		for(int j = h[i]; j <= x; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
	}
	cout << dp[n - 1][x];
}