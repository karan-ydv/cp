#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    string x = s.substr(0, s.find('='));
    string y = s.substr(s.find('=') + 1);
    int n = x.length(), m = stoi(y);
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1 << 30));
    pair<int, int> prev[n + 1][m + 1];
    int nxt[n + 1];
    nxt[n] = n;
    for(int i = n - 1; i > 0; i--)
        nxt[i] = x[i - 1] == '0' ? nxt[i + 1] : i;

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int v = 0, j;
        for(j = nxt[i]; j <= n; j++)
        {
            v = v * 10 + (x[j - 1] - '0');
            if(v > m)   break;
            for(int k = m; k >= v; k--)
            if(dp[j][k] > dp[i - 1][k - v]  + 1)
            {
                dp[j][k] = dp[i - 1][k - v]  + 1;
                prev[j][k] = {i - 1, k - v};
            }
        }
    }

    string ans = "=" + y;
    reverse(ans.begin(), ans.end());
    for(int i = n; i > 0; )
    {
        auto [j, k] = prev[i][m];
        for(; i > j; )  ans += x[--i];
        ans += '+';
        m = k;
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans;
}