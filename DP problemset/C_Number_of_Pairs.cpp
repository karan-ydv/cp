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
        int n, l, r;    cin >> n >> l >> r;
        int a[n];   for(int &x: a)  cin >> x;
        sort(a, a + n);
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            auto j = lower_bound(a + i + 1, a + n, l - a[i]);
            auto k = upper_bound(a + i + 1, a + n, r - a[i]);
            ans += k - j;
        }
        cout << ans << '\n';
    }
}