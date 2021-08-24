#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

const int N = 105;
int dp[N][N][N];

// dp[i][j][k] = number of ways that there were i players at begining and now
//               there are j players left to play and k of them are eliminated

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < N; i++)
    {
        dp[i][i][0] = 1;
        // j players are left to play
        for(int j = 1; j < i; j++)
        {
            // in the first round k players eliminated
            for(int k = 0; k <= i; k++)
            {
                dp[i][j][k] += 
            }
        }
    }
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        cout << dp[n][0][n] << '\n';
    }
}