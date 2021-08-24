#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+69;
int dp[N][N], a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++)
    for(int j = 0; j < N; j++)
        dp[i][j] = 1;
    
    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        a[0] = a[1], a[n + 1] = a[n];

        int prev[N] = {};
        int best[N] = {};

        int ans = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = k; j >= 1; j--)
            {
                dp[i][j] = max(best[j - 1] + 1, dp[prev[a[i]]][j] + 1);
                ans = max(ans, dp[i][j]);
                best[j] = max(best[j], dp[i][j]);
            }
            dp[i][0] = dp[ prev[a[i]] ][0] + 1;
            best[0] = max(best[0], dp[i][0]);
            prev[a[i]] = i;
        }
        cout << ans << '\n';
    }
}