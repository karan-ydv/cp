#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, h;   cin >> n >> h;
        int a[n];   for(int &x: a)  cin >> x;
        sort(a, a + n);
        int beg = 1, end = 1e18, ans;
        auto fun = [&](int m)
        {
            int x = 0;
            for(int i = 0, p = 0; i < n and x < h; i++) {
                x += min(m, a[i] + m - 1 - p);
                p = a[i] + m - 1;
            }
            return x >= h;
        };
        while(beg <= end)
        {
            int mid = (beg + end) / 2;
            if(fun(mid))
                ans = mid, end = mid - 1;
            else
                beg = mid + 1;
        }
        cout << ans << '\n';
    }
}