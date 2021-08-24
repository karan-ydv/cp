#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int dp[11] = {};
    dp[0] = 1;
    for(int i = 1; i < 11; i++)
    {
        dp[i] = dp[i - 1] * 10 + 1;
        // cerr << dp[i] << '\n';
    }
    auto fun = [&](int n)
    {
        int ret = 0;
        for(int i = 0; n; i++, n /= 10)
        {
            ret += (n % 10) * dp[i];
        }
        return ret;
    };
    int t;	cin >> t;
    while(t--)
    {
        int l, r;   cin >> l >> r;
        int ans = fun(r) - fun(l);
        cout << ans << '\n';
    }
}