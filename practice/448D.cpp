#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;    cin >> n >> m >> k;
    if(n > m) swap(n, m);
    int beg = 1, end = n * m, ans = 0;
    auto fun = [&](int x)
    {
        int c = 0;
        for(int i = 1; i <= n; i++)
            c += min(x / i, m);
        return c;
    };
    while(beg <= end)
    {
        int mid = (beg + end) >> 1;
        if(fun(mid) >= k)
            ans = mid, end = mid - 1;
        else
            beg = mid + 1;
    }
    cout << ans;
}