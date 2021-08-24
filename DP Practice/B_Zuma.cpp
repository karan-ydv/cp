#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int dp[N][N], A[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> A[i], dp[i][i] = 1;
        dp[i - 1][i] = 1 + (A[i - 1] != A[i]);
    }
    
    for(int j = 2; j < n; j++)
    for(int i = 1; i + j <= n; i++)
    {
        int &x = dp[i][i + j];
        x = 1 + dp[i + 1][i + j];
        if(A[i + 1] == A[i])
            x = min(x, 1 + dp[i + 2][i + j]);
        if(A[i + j] == A[i])
            x = min(x, dp[i + 1][i + j - 1]);
        for(int k = i + 2; k < i + j; k++) if(A[i] == A[k])
            x = min(x, dp[i + 1][k - 1] + dp[k + 1][i + j]);
    }

    cout << dp[1][n];
}