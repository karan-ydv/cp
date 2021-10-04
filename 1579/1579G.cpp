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
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        int beg = 1, end = 1e8, ans;
        auto fun = [&](int m)
        {
            int l = 0, r = a[0];
            for(int i = 1; i < n; i++)
            {
                if(r + a[i] - l + 1 <= m)
                    r += a[i];
                else if([i])
                {

                }
            }
            return r - l + 1 <= m;
        };
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(fun(mid))
                ans = mid, end = mid - 1;
            else
                beg = mid + 1;
        }
        cout << ans << '\n';
    }
}