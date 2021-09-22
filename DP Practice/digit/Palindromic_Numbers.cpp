#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int fun(string s)
{
    int n = s.length();
    int dp[n + 1][2];
    dp[0][0] = 1;
    for(int i = 0; i < n / 2; i++)
    {
        for(int d = 0; d < 10; d++)
            dp[i + 1][1] += dp[i][1];
        for(int d = 0; d <= s[i] - '0'; d++)
            dp[i + 1][d < s[i] - '0'] += dp[i][0];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        int a; string b;
        cin >> a >> b;
        cout << fun(b) - fun(to_string(a - 1)) << '\n';
    }
}