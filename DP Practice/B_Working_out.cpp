#include <bits/stdc++.h>
#define int int64_t
using namespace std;

typedef pair<int, int> pii;
#define FOR(i, j, k) for(int32_t i = j; i <= k; i++)
#define ROF(i, j, k) for(int32_t i = j; i >= k; i--)

const int N = 1e3+5;
int dp[N][N][4], A[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m)	cin >> A[i][j];
	
	FOR(i, 1, n) FOR(j, 1, m)	dp[i][j][0] = max(dp[i][j - 1][0], dp[i - 1][j][0]) + A[i][j];
	ROF(i, n, 1) FOR(j, 1, m)	dp[i][j][1] = max(dp[i][j - 1][1], dp[i + 1][j][1]) + A[i][j];
	FOR(i, 1, n) ROF(j, m, 1)	dp[i][j][2] = max(dp[i][j + 1][2], dp[i - 1][j][2]) + A[i][j];
	ROF(i, n, 1) ROF(j, m, 1)	dp[i][j][3] = max(dp[i][j + 1][3], dp[i + 1][j][3]) + A[i][j];
	
	int ans = 0, x;
	FOR(i, 2, n - 1) FOR(j, 2, m - 1)
	{
		x = dp[i - 1][j][0] + dp[i + 1][j][3] + dp[i][j - 1][1] + dp[i][j + 1][2];
		ans = max(ans, x);
		x = dp[i][j - 1][0] + dp[i][j + 1][3] + dp[i + 1][j][1] + dp[i - 1][j][2];
		ans = max(ans, x);
	}
	cout << ans;
}