#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h1, m1; cin >> h1 >> m1;
    int h2, m2; cin >> h2 >> m2;

    int x = abs(h2 - h1);
    x = min(x, 24 - x);
    int y = abs(m2 - m1);
    y = min(y, 60 - y);
    cout << x + y;
}