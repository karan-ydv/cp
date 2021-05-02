#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mx = 2020;
int dp[mx][mx], arr[mx];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int s[n];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);
	n -= 1;
	
	for(int i = 1; i <= n; i++)
		arr[i] = s[i] - s[i - 1];
	partial_sum(arr + 1, arr + n + 1, arr + 1);

	for(int i = 1; i <= n; i++)
		dp[i][i] = arr[i] - arr[i - 1];
	
	for(int i = 1; i <= n; i++)
	for(int j = 1; j + i <= n; j++)
	{
		dp[j][j + i] = LLONG_MAX;
		dp[j][j + i] = min(dp[j][j + i], dp[j + 1][j + i] + arr[j + i] - arr[j - 1]);
		dp[j][j + i] = min(dp[j][j + i], dp[j][j + i - 1] + arr[j + i] - arr[j - 1]);
	}
	cout << dp[1][n];
}