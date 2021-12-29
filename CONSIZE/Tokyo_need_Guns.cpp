#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, ans = 1e9, i, p, c, d;   cin >> n >> x;
    int a[n];   for(int &x: a)  cin >> x;
    sort(a, a + n);
    p = lower_bound(a, a + n, 0) - a;
    for(i = min(p, n - x); i >= 0; i--)
        c = abs(0 - a[i]), d = abs(a[i + x - 1]), ans = min({ans, c + 2 * d, 2 * c + d});
    cout << ans;
}