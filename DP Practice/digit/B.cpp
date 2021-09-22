#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int fun(string s)
{
    int n = s.length();
    int dp[n + 1][20][2] = {};
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++)
    for(int j = 0; j <= 10; j++)
    {
        for(int d = 0; d < 10; d++)
            dp[i + 1][j + d][1] += dp[i][j][1];
        for(int d = 0; d <= s[i] - '0'; d++)
            dp[i + 1][j + d][d < s[i] - '0'] += dp[i][j][0];
    }
    return dp[n][10][0] + dp[n][10][1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, ans;  cin >> k;
    int beg = 0, end = 1e8;
    while(beg <= end)
    {
        int mid = beg + end >> 1;
        if(fun(to_string(mid)) >= k)
            end = mid - 1, ans = mid;
        else
            beg = mid + 1;
    }
    cout << ans;
}