#include <bits/stdc++.h>
using namespace std;

const int N = 303;
int dp[N][N][N], a[N], b[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= x; j++)
    for(int k = 0; k <= y; k++)
        dp[i][j][k] = 1e5;
    
    for(int i = 0; i <= n; i++)
        dp[i][0][0] = 0;
    
    for(int i = 1; i <= n; i++)
    for(int j = 0; j <= x; j++)
    for(int k = 0; k <= y; k++)
    {
        int &x = dp[i][j][k];
        int p = max(0, j - a[i]);
        int q = max(0, k - b[i]);
        x = min({x, dp[i - 1][j][k], dp[i - 1][p][k] + 1, dp[i - 1][j][q] + 1, dp[i - 1][p][q] + 1});
    }
    
    if(dp[n][x][y] > n)
        dp[n][x][y] = -1;
    cout << dp[n][x][y];
}