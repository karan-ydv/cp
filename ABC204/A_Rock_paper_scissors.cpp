#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y;   cin >> x >> y;
    if(x == y)
        cout << x;
    else
        cout << (3 - x - y) << '\n';
}