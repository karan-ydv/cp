#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 1e4+5;
int dp[3][105][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; int n, d;
    cin >> s >> d;
    n = s.length();

    dp[0][0][0] = 1;
    for(int i = 0, c = 0; i < n; i++, c ^= 1)
    {
        fill_n(dp[c ^ 1][0], 210, 0);
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < 10; k++)
                (dp[c ^ 1][(j + k) % d][1] += dp[c][j][1]) %= mod;
            for(int k = 0; k <= s[i] - '0'; k++)
                (dp[c ^ 1][(j + k) % d][k < s[i] - '0'] += dp[c][j][0]) %= mod;
        }
    }
    int ans = (dp[n & 1][0][0] + dp[n & 1][0][1] + mod - 1) % mod;
    cout << ans;
}