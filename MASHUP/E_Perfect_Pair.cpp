#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, m;    cin >> x >> y >> m;
    if(x >= m or y >= m)    return cout << "0", 0;
    if(x <= 0 and y <= 0)   return cout << "-1", 0;

    int c = 0;
    if(x > y)   swap(x, y);
    if(x < 0)
    {
        c += (0 - x) / y;
        x += c * y;
        if(x < 0)
        {
            x += y;
            c++;
        }
    }
    while(x < m and y < m)
    {
        if(x > y)   swap(x, y);
        x += y;
        c ++;
    }
    cout << c;
}