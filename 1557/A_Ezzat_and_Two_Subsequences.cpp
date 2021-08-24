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
        sort(a, a + n);
        long double sumR = accumulate(a + 1, a + n, 0ll);
        long double sumL = a[0];
        long double ans = -1e18;
        for(int i = 1; i < n; i++) {
            ans = max(ans, (sumL / i) + (sumR / (n - i)));
            sumL += a[i];
            sumR -= a[i];
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}