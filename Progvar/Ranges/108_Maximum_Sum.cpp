#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 101;
int A[N][N], dp[N][N];
int sum(int a, int b, int x, int y) {
	a --, b --;
	int s = dp[x][y] - dp[a][b];
	s -= dp[x][b] - dp[a][b];
	s -= dp[a][y] - dp[a][b];
	return s;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n)
	{
		for(int i = 1; i <= n; i++)
		{
			int temp = 0;
			for(int j = 1; j <= n; j++)
			{
				cin >> A[i][j];
				temp += A[i][j];
				dp[i][j] = dp[i - 1][j] + temp;
			}
		}
		int ans = -2e9;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = i; k <= n; k++) {
					for(int l = j; l <= n; l++) {
						ans = max(sum(i, j, k, l), ans);
						}}}}
		cout << ans << '\n';
	}
}