#include <bits/stdc++.h>
using namespace std;

const int N = 707;
int dp[N][N];
bool twice[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    string s; cin >> s;
    s = "!" + s;
    
    for(int i = 1; i <= n; i++)
    for(int k = 1; i + k + k - 1 <= n; k++)
    {
        twice[i][k] = 1;
        for(int j = 0; j < k; j++)
        if(s[i + j] != s[i + k + j])
        {
            twice[i][k] = false;
            break;
        }
    }

    for(int j = 0; j <= n; j++)
    for(int i = 1; i + j <= n; i++)
    {
        int &x = dp[i][i + j];
        x = j + 1;
        for(int k = 1; k <= j; k++)
        {
            x = min(x, dp[i][i + k - 1] + dp[i + k][i + j]);
            if(twice[i][k])
            {
                int y = i;
                while(twice[y][k])
                {
                    y += k;
                    x = min(x, dp[i][i + k - 1] + dp[y + k][i + j]);
                }
            }
        }    
    }
    cout << dp[1][n];
}