#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool between(int a, int b, int x)
{
    if(b < a) swap(a, b);
    return a < x and x < b;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int xa, ya; cin >> xa >> ya;
        int xb, yb; cin >> xb >> yb;
        int xf, yf; cin >> xf >> yf;
        int ans;
        if (xa == xb)
        {
            ans = abs(ya - yb);
            if (xa == xf and between(ya, yb, yf))
                ans += 2;
        }
        else if (ya == yb)
        {
            ans = abs(xa - xb);
            if (ya == yf and between(xa, xb, xf))
                ans += 2;
        }
        else
            ans = abs(xa - xb) + abs(ya - yb);
        cout << ans << '\n';
    }
}