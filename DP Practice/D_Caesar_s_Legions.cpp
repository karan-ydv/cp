#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8;
const int N = 105;
int dp[N][N][21][2];

/*
dp[i][j][k][0] = no. of beautiful arrangments having i footmen, j horsemen 
                    such that there are k successive footmen at the end
dp[i][j][k][1] = no. of beautiful arrangments having i footmen, j horsemen 
                    such that there are k successive horsemen at the end
*/


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    

    dp[0][0][0][0] = 1;

    int a, b, c, d;
    for(a = 0; a <= n1; a++)
    for(b = 0; b <= n2; b++)
    for(c = 0; c <= 10; c++)
    {
        // put a footmen at end
        if(c < k1)
        (dp[a + 1][b][c + 1][0] += dp[a][b][c][0]) %= mod;
        (dp[a + 1][b][1][0] += dp[a][b][c][1]) %= mod;
        //put a horsemen at end
        if(c < k2)
        (dp[a][b + 1][c + 1][1] += dp[a][b][c][1]) %= mod;
        (dp[a][b + 1][1][1] += dp[a][b][c][0]) %= mod;
    }

    int ans = 0;
    for(c = 1; c <= k1; c++)
        (ans += dp[n1][n2][c][0]) %= mod;
    for(c = 1; c <= k2; c++)
        (ans += dp[n1][n2][c][1]) %= mod;
    cout << ans;
}