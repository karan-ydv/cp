#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n], p[n], ans[n];
    for(int &x: a) cin >> x;
    iota(p, p + n, 0);
    sort(p, p + n, [&](int x, int y){
        return a[x] < a[y];
    });
    sort(a, a + n);
    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for(int i = 0; i + 2 < n; i++)
    {
        dp[i + 3] = min(dp[i + 3], dp[i] + a[i + 2] - a[i]);
        if(i + 3 < n)
        dp[i + 4] = min(dp[i + 4], dp[i] + a[i + 3] - a[i]);
        if(i + 4 < n)
        dp[i + 5] = min(dp[i + 5], dp[i] + a[i + 4] - a[i]);
    }
    int t = 1;
    for(int i = n; i >= 3; t++) {
        int k = 5;
        if(dp[i] == dp[i - 3] + a[i - 1] - a[i - 3])
            k = 3;
        else if(dp[i] == dp[i - 4] + a[i - 1] - a[i - 4])
            k = 4;
        for(int j = 1; j <= k; j++)
            ans[p[i - j]] = t;
        i -= k;
    }
    cout << dp[n] << ' ' << t - 1 << '\n';
    for(int x: ans) cout << x << ' ';
}