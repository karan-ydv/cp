#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 501;
int a[N][N], b[N][N], dp[N][N][2];
int hpref[N][N], vpref[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m, n or m)
	{
		n++, m++;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				cin >> hpref[i][j];
				hpref[i][j] += hpref[i][j - 1];
			}
		}
		for( int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				cin >> vpref[i][j];
				vpref[i][j] += vpref[i - 1][j];
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				dp[i][j][0] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + vpref[i][j];
				dp[i][j][1] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + hpref[i][j];
			}
		}
		int ans = max(dp[n - 1][m - 1][1], dp[n - 1][m - 1][0]);
		cout << ans << '\n';
	}
}