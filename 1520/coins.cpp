#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y;   cin >> x >> y;
    int D = 1 + 8 * (x + y);
    int s = sqrt(D);
    if(s * s != D or s % 2 == 0)
        return cout << "-1", 0;
    
    int n = (s - 1) / 2;
    int ans = 0;
    for(int i = n; i > 0 and x > 0; i--)
    {
        if(i <= x)
        {
            x -= i;
            ans++;
        }
    }

    if(x != 0)
        return cout << "-1", 0;
    cout << ans;
}