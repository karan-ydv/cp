#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 998244353;
const int N = 1069;
int dp[N][2 * N][4];

int f(int x, int y)
{
    bitset<4> z(x ^ y);
    int ret = z.count();
    if(ret) ret -= (y == 0 or y ==  3);
    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;   cin >> n >> k;
    
    dp[1][1][0] = dp[1][2][1] = dp[1][2][2] = dp[1][1][3] = 1;

    for(int i = 1; i < n; i++)
    for(int j = 0; j <= k; j++)
    for(int a = 0; a <= 3; a++) if(dp[i][j][a])
    for(int b = 0; b <= 3; b++)
        (dp[i + 1][j + f(a, b)][b] += dp[i][j][a]) %= mod;
    
    int ans = 0;
    for(int i = 0; i < 4; i++)    
        (ans += dp[n][k][i]) %= mod;
    cout << ans;
}