#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int fun(string s)
{
    int n = s.length();
    int dp[20][5][2] = {};
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 4; j++)
    {
        for(int d = 0; d < 10; d++)
            dp[i + 1][j + (d != 0)][1] += dp[i][j][1];
        for(int d = 0; d <= s[i] - '0'; d++)
            dp[i + 1][j + (d != 0)][d < s[i] - '0'] += dp[i][j][0];
    }
    int ans = 0;
    for(int i: {0, 1, 2, 3})
        ans += dp[n][i][0] + dp[n][i][1];
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string b; int a;
        cin >> a >> b;
        cout << fun(b) - fun(to_string(a - 1)) << '\n';
    }
}