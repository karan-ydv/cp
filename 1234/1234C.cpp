#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        string s[3];
        cin >> s[1] >> s[2];
        s[1] = "!" + s[1];
        s[2] = "!" + s[2];

        bool dp[4][n + 2][3];
        fill_n(dp[0][0], 12 * (n + 2), 0);

        dp[1][1][0] = 1;
        for(int j = 1; j <= n; j++)
        for(int i : {1, 2, 1, 2})
        {
            char c = s[i][j];
            if(dp[i][j][0])
            {
                if(c == '1' or c == '2')
                    dp[i][j + 1][0] = 1;
                else
                {
                    dp[i + 1][j][1] = 1;
                    dp[i - 1][j][2] = 1;
                }
            }
            if(dp[i][j][1])
            {
                if(c == '1' or c == '2');
                else
                    dp[i][j + 1][0] = 1;
            }
            if(dp[i][j][2])
            {
                if(c == '1' or c == '2');
                else
                    dp[i][j + 1][0] = 1;
            }
        }

        dp[2][n + 1][0] ? cout << "YES\n" : cout << "NO\n";
    }
}