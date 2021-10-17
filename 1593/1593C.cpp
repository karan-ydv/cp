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
        int n, k;   cin >> k >> n;
        int a[n];   for(int &x: a)  cin >> x;
        sort(a, a + n, greater<int>());
        int beg = 1, end = n, ans = 0;
        auto fun = [&](int m)
        {
            int c = 0;
            for(int i = 0; i < m; i++)
            {
                if(c >= a[i])   return false;
                c += k - a[i];
            }
            return true;
        };
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(fun(mid))
                ans = mid, beg = mid + 1;
            else
                end = mid - 1;
        }
        cout << ans << '\n';
    }
}