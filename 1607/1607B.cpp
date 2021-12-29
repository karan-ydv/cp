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
        int x, n;   cin >> x >> n;
        if(n == 0)
        {
            cout << x << '\n';
            continue;
        }
        if(x & 1)
        {
            x += 1;
            x += 4 * ((n - 1) / 4);
            for(int m = 2 + 4 * ((n - 1) / 4); m <= n; m++)
            {
                if(x & 1)
                    x += m;
                else
                    x -= m;
            }
        }
        else
        {
            x -= 1;
            x -= 4 * ((n - 1) / 4);
            for(int m = 2 + 4 * ((n - 1) / 4); m <= n; m++)
            {
                if(x & 1)
                    x += m;
                else
                    x -= m;
            }
        }
        cout << x << '\n';
    }
}