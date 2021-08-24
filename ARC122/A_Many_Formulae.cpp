#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 1e5+69;
int A[N], dp[N][2], sum[N][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];
    dp[1][0] = 1;
    sum[1][0] = A[1];
    for(int i = 2; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][0];
        (dp[i][0] += dp[i - 1][0] + dp[i - 1][1]) %= mod;
        (sum[i][0] += dp[i][0] * A[i] % mod + sum[i - 1][0] + sum[i - 1][1]) %= mod;
        (sum[i][1] += sum[i - 1][0] + mod - dp[i][1] * A[i] % mod) %= mod;
    }
    int ans = (sum[n][0] + sum[n][1]) % mod;
    cout << ans;
}