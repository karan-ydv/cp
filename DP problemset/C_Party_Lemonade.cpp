#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, L;
    cin >> n >> L;
    int cost[32];
    fill_n(cost, 32, 1LL << 62);
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    for(int i = 0; i < 30; i++)
        cost[i + 1] = min(cost[i + 1], cost[i] << 1);
    for(int i = 30; i > 0; i--)
        cost[i - 1] = min(cost[i], cost[i - 1]);
    int ans = 1LL << 62;
    function<void(int, int)> fun = [&](int x, int y)
    {
        if(x == 0)
        {
            ans = min(ans, y);
            return;
        }
        int b = 63 - __builtin_clzll(x);
        ans = min(ans, y + cost[b + 1]);
        y += cost[b];
        fun(x ^ (1 << b), y);
    };
    fun(L, 0);
    cout << ans;
}