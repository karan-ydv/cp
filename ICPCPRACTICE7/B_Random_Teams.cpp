#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    int mx = (n - m) * (n - m + 1) / 2;
    int x = n / m;
    int y = n % m;
    int mn = (m - y) * (x * (x - 1) / 2) + y * (x * (x + 1) / 2);
    cout << mn << ' ' << mx;
}