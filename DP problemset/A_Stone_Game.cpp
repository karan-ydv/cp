#include <bits/stdc++.h>
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
        int x = find(a, a + n, 1) - a;
        int y = find(a, a + n, n) - a;
        if(x > y)   swap(x, y);
        int p = x + 1, q = y - x, r = n - y;
        int ans = min({p + q, q + r, p + r});
        cout << ans << '\n';
    }
}