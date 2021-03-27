#include <bits/stdc++.h>
#define int long long
using namespace std;

int fun(int x)
{
    if(x < 10)  return x+1;
    string s = to_string(x);
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(10));
    int ans = 10;
    for(int i = 1; i < 10; i++) dp[0][i] = 1;
    for(int i = 1; i < n - 1; i++)
    {
        int c = 0;
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            if(k != j) dp[i][j] += dp[i - 1][k];
            ans += dp[i][j];
        }
    }
    dp = vector<vector<int>>(n, vector<int>(10));
    for(int i = 1; i <= (s[0] - '0'); i++) dp[0][i] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= s[i] - '0'; j++)
        {
            for(int k = 0; k < 10; k++)
            if(k != j) dp[i][j] += dp[i - 1][k];
        }
        for(int j = s[i] - '0' + 1; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            if(k != j )
            {
                // edge case : 333 (i > 1 and s[i - 1] == s[i - 2])
                if(k != s[i - 1] - '0' or (i > 1 and s[i - 1] == s[i - 2]))
                    dp[i][j] += dp[i - 1][k];
                else
                    dp[i][j] += max(dp[i - 1][k] - 1, 0ll);
            }
        }
    }
    for(int i = 0; i < 10; i++) ans += dp[n - 1][i];
    return ans;
}
int32_t main() {
    int a, b;   cin >> a >> b;
    cout << fun(b) - fun(a - 1);
}