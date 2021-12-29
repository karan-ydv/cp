#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;  cin >> x;
    if(x >= 90)
        return cout << "expert", 0;
    if(x >= 70)
        return cout << 90 - x, 0;
    if(x >= 40)
        return cout << 70 - x, 0;
    cout << 40 - x;
}