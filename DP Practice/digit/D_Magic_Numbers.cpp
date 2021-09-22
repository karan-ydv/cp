#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int fun(string s, int k, int m)
{
    int n = s.length();
    int dp[n + 1][m][2] = {};
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    {
        for(int d = 0; d < 10; d++) if(i or d)
        {
            if(i & 1)   if(d != k)  continue; else;
            else        if(d == k)  continue; else;
            (dp[i + 1][(j * 10 + d) % m][1] += dp[i][j][1]) %= mod;
        }
        for(int d = 0; d <= s[i] - '0'; d++) if(i or d)
        {
            if(i & 1)   if(d != k)  continue; else;
            else        if(d == k)  continue; else;
            (dp[i + 1][(j * 10 + d) % m][d < s[i] - '0'] += dp[i][j][0]) %= mod;
        }
    }
    return (dp[n][0][0] + dp[n][0][1]) % mod;
}

bool isMagic(string s, int d, int m)
{
    for(int i = 0; i < s.length(); i++)
    if(i & 1)   if(s[i] - '0' != d) return false;   else;
    else        if(s[i] - '0' == d) return false;   else;

    int x = 0;  for(char c: s) x = (x * 10 + (c - '0')) % m;
    return x == 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, d;
    string a, b;
    cin >> m >> d >> a >> b;
    int ans = (fun(b, d, m) + mod - fun(a, d, m) + isMagic(a, d, m)) % mod;
    cout << ans;
}