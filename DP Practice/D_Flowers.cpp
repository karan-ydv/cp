#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 1e5+5;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, k;   cin >> t >> k;
    dp[0] = 1;
    for(int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1];
        if(i >= k)
        (dp[i] += dp[i - k]) %= mod;
    }
    partial_sum(dp, dp + N, dp);
    while(t--)
    {
        int a, b;   cin >> a >> b;
        cout << (dp[b] - dp[a - 1]) % mod << '\n';
    }
}