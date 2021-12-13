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
        int a, b;   cin >> a >> b;
        int mn = 2 * a;
        int mx = a * b * (a * b - 1);
        cout << mn << ' ' << mx << '\n';
    }
}