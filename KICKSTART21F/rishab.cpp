#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int fun(int l, int r, int x)
{
    return r / x - (l - 1) / x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    int lcm = x * y / __gcd(x, y);
    int ans = fun(l, r, x) + fun(l, r, y) - fun(l, r, lcm);
    cout << (r - l + 1 - ans);
}