#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int N = 10;
const int M = 2e5 + 5;

int dp[M][10][10];

int base[10][10] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;

	for(int i = 0; i < N; i++)
		dp[0][i][i] = 1;

	for(int a = 1; a < M; a++)
	{
		for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
		for(int k = 0; k < N; ++k)
			dp[a][i][k] = (dp[a][i][k] + (long long) dp[a - 1][i][j] * base[j][k]) % mod;
	}

	for(int _ = 0; _ < t; _++)
	{
		int n, m;	cin >> n >> m;
		vector<int> freq(10);
		while(n)
		{
			freq[n % 10]++;
			n /= 10;
		}

		long long ans = 0;
		for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			ans = (ans + (long long)dp[m][i][j] * freq[j]) % mod;

		cout << ans << '\n';
	}
}