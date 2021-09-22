#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int f(string s)
{
    int n = s.length();
    int dp[n + 1][2] = {};
    int f[n + 1][10][2] = {};
    f[0][0][0] = 1;
    for(int i = 0, p = 1; i < n; i++, (p *= 10) %= mod)
    for(int j = 0; j < 10; j++)
    {
        for(int d = 0; d < 10; d++)
            
    }
    return dp[n][0] + dp[n][1];
}

int g(string s)
{
    reverse(s.begin(), s.end());
    int x = 0;
    char prev = '!';
    for(char c: s)
    {
        x *= 10;
        if(c != prev)
            x += c - '0';
        x %= mod;
        prev = c;
    }
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int ans = (f(a) + mod - f(a) + g(a)) % mod;
        cout << ans << '\n';
    }
}