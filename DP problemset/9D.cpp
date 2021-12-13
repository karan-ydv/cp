#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 36;
int dp[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h;   cin >> n >> h;
    dp[0][0] = dp[1][1] = 1;
    for(int i = 2; i <= n; i++)
    for(int j = 2; j <= i; j++)
    for(int k = 1; k <= i; k++)
    {
        for(int a = 0; a <= j - 1; a++)
            dp[i][j] += dp[k - 1][j - 1] * dp[i - k][a];

        for(int a = 0; a < j - 1; a++)
            dp[i][j] += dp[k - 1][a] * dp[i - k][j - 1];
    }
    int ans = 0;
    for(int i = h; i <= n; i++)
        ans += dp[n][i];
    cout << ans;
}