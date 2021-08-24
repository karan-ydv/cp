#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    int a[n], b[m + 2];
    for(int &x: a)  cin >> x;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    b[m] = -3e9;
    b[m + 1] = 3e9;
    m += 2;
    sort(a, a + n);
    sort(b, b + m);
    // for(int x: a)   cerr << x << ' '; cerr << '\n';
    // for(int x: b)   cerr << x << ' '; cerr << '\n';
    int ans = 1e10;
    for(int i = 0; i < n; i++)
    {
        int x = lower_bound(b, b + m, a[i]) - b;
        ans = min(ans, abs(a[i] - b[x]));
        ans = min(ans, abs(a[i] - b[x - 1]));
    }
    cout << ans;
}