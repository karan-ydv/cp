#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 101;
const int inf = 1LL << 60;
int dp[N][N][N];
int p[N][N];
int c[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, o;
    cin >> n >> m >> o;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> p[i][j];

    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    for(int k = 0; k < N; k++)
        dp[i][j][k] = inf;
    
    if(c[1] == 0)
        for(int i = 1; i <= m; i++)
            dp[1][1][i] = p[1][i];
    else
        dp[1][1][c[1]] = 0;
    
    for(int i = 2; i <= n; i++)
    for(int j = 1; j <= o; j++)
    if(c[i] == 0)
    {
        for(int k = 1; k <= m; k++)
        {
            dp[i][j][k] = min(dp[i - 1][j][k] + p[i][k], dp[i][j][k]);
            for(int a = 1; a <= m; a++) if(a != k)
            dp[i][j][k] = min(dp[i - 1][j - 1][a] + p[i][k], dp[i][j][k]);
        }
    }
    else
    {
        dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j][c[i]]);
        for(int k = 1; k <= m; k++) if(k != c[i])
            dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j - 1][k]);
    }

    int ans = inf;
    for(int i = 1; i <= m; i++)
        ans = min(ans, dp[n][o][i]);
    if(ans == inf) ans = -1;
    cout << ans;
}