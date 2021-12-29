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
        int x, y;   cin >> x >> y;
        if(y < x)
            cout << x - y << '\n';
        else
        {
            int d = y - x;
            int ans = ((d + 1) / 2) + (d & 1);
            cout << ans << '\n';
        }
    }
}