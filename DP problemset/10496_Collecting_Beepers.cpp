#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        int a, b;   cin >> a >> b;
        bool A[n][m] = {};
        int p; cin >> p;
        int x[p], y[p];
        for(int i = 0; i < p; i++)
            cin >> x[i] >> y[i];
        int dp[1 << p][p];
        fill_n(dp[0], p * (1 << p), 1e9);
        for(int i = 0; i < p; i++)  dp[1 << i][i] = abs(x[i] - a) + abs(y[i] - b);
        for(int i = 1; i < (1 << p); i++)
        {
            for(int k = 0; k < p; k++) if(i & (1 << k))
            for(int j = 0, b = 1; j < p; j++, b <<= 1)
            if(!(i & b))
            {
                dp[i|b][j] = min(dp[i|b][j], dp[i][k] + abs(x[j] - x[k]) + abs(y[j] - y[k]));
            }
        }
        int ans = 1e9;
        for(int i = 0; i < p; i++) {
            ans = min(ans, dp[(1 << p) - 1][i] + abs(x[i] - a) + abs(y[i] - b));
        }
        cout << "The shortest path has length " << ans << '\n';
    }
}