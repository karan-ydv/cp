#include <bits/stdc++.h>
using namespace std;

const int N = 2012;
int dp[N][N], A[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1e9;

    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        int a;  cin >> a;
        for (int j = 0; j < h; j++)
        {
            int t1 = (j + a) % h;
            int t2 = (j + a - 1) % h;
            int &x = dp[i + 1][t1];
            int &y = dp[i + 1][t2];
            x = max(x, dp[i][j] + (l <= t1 and t1 <= r));
            y = max(y, dp[i][j] + (l <= t2 and t2 <= r));
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
        ans = max(ans, dp[n][i]);
    cout << ans;
}