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
            if(d & 1)
                cout << d / 2 + 2 << '\n';
            else
                cout << d / 2 << '\n';
        }
    }
}