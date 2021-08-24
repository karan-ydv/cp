#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 3e3+5;
int dp[N][N][4], val[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        val[x][y] = v;
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        for(int k: {0, 1, 2, 3})
        {
            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][k] + val[i][j]);
            if(k)
            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + val[i][j]);
        }
    }
    
    int ans = 0;
    for(int i: {0, 1, 2, 3})
        ans = max(ans, dp[n][m][i]);
    cout << ans;
}