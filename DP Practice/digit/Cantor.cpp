#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int fun(string s, string set)
{
    int n = s.length();
    int dp[n + 1][2] = {};
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(char d: set)
            dp[i + 1][1] += dp[i][1];
        if(set[0] != '0') dp[i + 1][1] ++;
        for(char d: set) if(d <= s[i])
            dp[i + 1][d < s[i]] += dp[i][0];
    }
    return dp[n][1] + dp[n][0];
}

string base(int n, int b)
{
    string s = "";
    for(; n; s += '0' + n % b, n /= b);        
    reverse(s.begin(), s.end());
    return s;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r, b; string s;
    while(cin >> l >> r >> b >> s, l != -1)
    {
        string set = "";
        for(int i = 0; i < b; i++)
            if(s[i] == 'S') set += '0' + i;
        int ans = fun(base(r, b), set) - fun(base(l - 1, b), set);
        cout << ans << '\n';
    }
}