#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 420;
int dp[N][N];
int ncr[N][N];
int pw[N];

void precompute(int mod)
{
    ncr[1][0] = 1;
    ncr[1][1] = 1;
    for(int i = 2; i < N; i++)
    {
        ncr[i][0] = 1;
        for(int j = 1; j <= i; j++)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
    }
    pw[0] = 1;
    for(int i = 1; i < N; i++)
        (pw[i] = pw[i - 1] << 1) %= mod;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, mod; cin >> n >> mod;
    precompute(mod);
    
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
    for(int k = 1; k + i <= n; k++)
        (dp[i + k + 1][j + k] += dp[i][j] * pw[k - 1] % mod * ncr[j + k][k]) %= mod;

    int ans = 0;
    for(int i = 0; i <= n; i++)
        (ans += dp[n + 1][i]) %= mod;
    
    cout << ans;
}