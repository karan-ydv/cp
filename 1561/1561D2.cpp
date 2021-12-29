#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 4e6+5;
int dp[N], f[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, mod;  cin >> n >> mod;
    int sum = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = sum;
        (sum += dp[i - 1]) %= mod;
        (dp[i] += dp[i - 1] + 1) %= mod;
        int x = (dp[i] - dp[i - 1] + mod) % mod;
        for(int j = i + i; j <= n; j += i)
            (dp[j] += x) %= mod;
    }
    cout << dp[n];
}