#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 18;
int dp[1 << N][N];
int a[N], c[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (k--)
    {
        int x, y; cin >> x >> y;
        cin >> c[x - 1][y - 1];
    }
    int p = 1 << n, ans = 0;
    for (int i = 0; i < p; i++) {
        int x = __builtin_popcount(i), y = 1;
        if (x < m)
        for (int j = 0; j < n; j++, y <<= 1)
        if (!(i & y))
        {
            for (int k = 0, z = 1; k < n; k++, z <<= 1)
            dp[i | y][j] = max(dp[i | y][j], dp[i][k] + a[j] + (i & z ? c[k][j] : 0));
            if (x == (m - 1))
            ans = max(ans, dp[i | y][j]);
        }
    }
    cout << ans;
}