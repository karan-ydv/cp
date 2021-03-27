#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        int a[n];   for(int &x: a)  cin >> x;
        sort(a, a + n, greater<int>());
        
        int b[n];   b[0] = a[0];
        int beg = 0, end = n, mid;
        for(int i = 1; i < n; i ++) {
            b[i] = b[i - 1] + a[i];
            if(a[i] >= 2 * k and beg == 0) {
                beg = i + 1;
            }
        }
        auto possible = [&](int m) {
            int W = b[m - 1] / 2;	
            int dp[m + 1][W + 1];
            for(int i = 0; i <= m; i++)
            for(int j = 0; j <= W; j++)
            {
                if(i == 0 or j == 0)
                    dp[i][j] = 0;
                else if (a[i - 1] <= j)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
            return dp[n][W] >= k and b[m - 1] - dp[n][W] >= k;
        };
        int ans = -1;
        if(beg > 0)
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(possible(mid))
                ans = mid, end = mid - 1;
            else
                beg = mid + 1;
        }
        cout << ans << '\n';
    }
}