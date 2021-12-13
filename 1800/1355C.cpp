#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int fun(int s)
{
    // no. of pairs of x, y such that x + y = s
    int l, r;
    if(s - a <= c)
        l = a;
    else
        l = s - c;
    
    if(s - b >= b)
        r = b;
    else
        r = s - b;
    return max(r - l + 1, 0);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d;

    long long ans = 0, p = 0;
    for(int s = b + c; s > d; s--)
        p += fun(s);
    
    for(int z = d; z >= c; z--)
    {
        ans += p;
        p += fun(z);
    }

    cout << ans;
}