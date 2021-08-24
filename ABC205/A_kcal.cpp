#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;   cin >> a >> b;
    double ans = a / 100.0 * b;
    cout << fixed << setprecision(20) << ans;
}