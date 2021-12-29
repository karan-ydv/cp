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
        int n, k;   cin >> n >> k;
        int a[n];   for(int &x: a)  cin >> x;
        sort(a, a + n);
        int p = lower_bound(a, a + n, 0) - a;
        int ans = 0;
        if(a[n - 1] > 0)
            ans += a[n - 1];
        for(int i = n - k - 1; i >= p; i -= k) {
            ans += 2 * a[i];
        }
        if(a[0] < 0)
            ans -= a[0];
        for(int i = k; i < p; i += k) {
            ans -= 2 * a[i];
        }
        if(a[0] < 0 and a[n - 1] > 0)
            ans += min(-a[0], a[n - 1]);
        cout << ans << '\n';
    }
}