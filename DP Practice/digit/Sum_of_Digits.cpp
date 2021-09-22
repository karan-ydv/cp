#include <bits/stdc++.h>
#define int uint64_t
using namespace std;

int fun(string s)
{
    int n = s.length();
    int dp[n + 1][2] = {};
    int f[n + 1][2] = {};
    f[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
            f[i + 1][1] += f[i][1],
            dp[i + 1][1] += dp[i][1] + j * f[i][1];
        for(int j = 0; j <= s[i] - '0'; j++)
            f[i + 1][j < s[i] - '0'] += f[i][0],
            dp[i + 1][j < s[i] - '0'] += dp[i][0] + j * f[i][0];
    }
    return dp[n][0] + dp[n][1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int64_t a, b;
    while(cin >> a >> b, !(a == -1 or b == -1))
    {
        int ans = fun(to_string(b));
        if(a > 1)
            ans -= fun(to_string(a - 1));
        cout << ans << '\n';
    }
}