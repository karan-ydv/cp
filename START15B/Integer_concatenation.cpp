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
        int n, l, r;
        cin >> n >> l >> r;
        int a[n], p[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n; i++) {
            p[i] = 1;
            for(int x = a[i]; x; x /= 10, p[i] *= 10);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int beg = 0, end = n - 1;
            int left = n;
            while(beg <= end)
            {
                int mid = beg + end >> 1;
                int x = a[i] * p[mid] + a[mid];
                if(x < l)
                    beg = mid + 1;
                else
                    left = mid, end = mid - 1;
            }
            int right = left;
            beg = left, end = n - 1;
            while(beg <= end)
            {
                int mid = beg + end >> 1;
                int x = a[i] * p[mid] + a[mid];
                if(x > r)
                    right = mid, end = mid - 1;
                else
                    right = mid + 1, beg = mid + 1;
            }
            // cout << a[i] << " : ";
            ans += right - left;
        }
        cout << ans << '\n';
    }
}