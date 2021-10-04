#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, x, y;
    cin >> n >> a >>  x >> y;
    if(n <= a)
        cout << n * x;
    else
    {
        int ans = a * x + (n - a) * y;
        cout << ans;
    }
}