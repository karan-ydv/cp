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
        int n;  cin >> n; int a[n];
        for(int &x: a)  cin >> x;
        sort(a, a + n);
        int ans = 0;
        for(int i = 1; i <= 108; i++)
        {
            ans = max(ans, i * (n - (lower_bound(a, a + n, i) - a)));
        }
        cout << ans << '\n';
    }
}