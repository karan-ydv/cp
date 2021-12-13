#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        string s[n];
        for(auto &x: s) cin >> x;

        int dp[n][m];
        for(int i = 0; i < n * m; i++)
            *(dp[0] + i) = 1e9;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            dp[i][j] *= s[i][j] == '0';
            if(i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
        for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
        {
            if(i + 1 < n) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            if(j + 1 < m) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
        }
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << dp[i][j] << " \n"[j == m - 1];
    }
}