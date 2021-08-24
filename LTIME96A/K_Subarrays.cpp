#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+5;
int dp[N][105], a[N];
int dp2[N][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;	cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        for(int i = 0; i <= n; i++)
        for(int j = 1; j <= k; j++)
            dp[i][j] = dp2[i][j] = -2e18;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] * j);
                dp[i][j] = max(dp[i][j], dp2[i - 1][j - 1] + a[i] * j);

                dp2[i][j] = max(dp2[i - 1][j], dp[i - 1][j] + a[i] * j);
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - 1] + a[i] * j);
            }
        }
        // for(int i = 1; i <= n; i++)
        // {
        //     cerr << i << ". ";
        //     for(int j = 0; j <= k; j++)
        //     {
        //         cerr << dp[i][j] << " \n"[j == k];
        //     }
        //     cerr << i << ". ";
        //     for(int j = 0; j <= k; j++)
        //     {
        //         cerr << dp2[i][j] << " \n"[j == k];
        //     }
        // }
        // cerr << '\n';
        cout << dp2[n][k] << '\n';
    }
}