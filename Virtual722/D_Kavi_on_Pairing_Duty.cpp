#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 998244353;
const int N = 1e6+5;
int dp[N], sum[N];
int divsum[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;

    for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j += i)
        divsum[j]++;

    dp[1] = sum[1] = 1;
    for(int i = 2; i <= n; i += 1)
    {
        dp[i] = (dp[i - 1] + sum[i - 2]) % mod;
        (dp[i] += divsum[i]) %= mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    cout << dp[n];
}