#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2077;
int dp[N][N], A[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;	cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    
    for(int i = 0; i <= n; i++)
    for(int j = 1; j <= n; j++)
        dp[i][j] = -1e18;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(dp[i - 1][j - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + A[i]);
        }
    }
    for(int i = n; i > 0; i--)
    if(dp[n][i] >= 0) return cout << i, 0;
    cout << "0";
}