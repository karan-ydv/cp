#include <bits/stdc++.h>
using namespace std;

const int N = 44;
const int M = 404;
int dp[N][M][M];
int A[N][3];
// dp[i][j][k] = minimum price to buy j gm of A and k gm of B from first i elements

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ma, mb;
    cin >> n >> ma >> mb;

    int suma = 0, sumb = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> A[i][j];
        suma += A[i][0], sumb += A[i][1];
    }
    
    fill_n(&dp[0][0][0], N * M * M, 1 << 30);
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0][0] = 0;
        int a = A[i][0], b = A[i][1], c = A[i][2];
        for(int j = 1; j <= suma; j++)
        for(int k = 1; k <= sumb; k++)
        {
            int &x = dp[i][j][k];
            x = min(x, dp[i - 1][j][k]);
            if(a <= j and b <= k)
            x = min(x, dp[i - 1][j - a][k - b] + c);
        }
    }

    int ans = 1 << 30;
    for(int g = 1; g * ma <= suma and g * mb <= sumb; g++)
        ans = min(ans, dp[n][g * ma][g * mb]);
    
    if(ans == 1 << 30)  ans = -1;
    cout << ans;
}