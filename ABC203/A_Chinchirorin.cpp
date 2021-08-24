#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;    cin >> a >> b >> c;
    if(a == b)    return cout << c, 0;
    if(c == b)    return cout << a, 0;
    if(a == c)    return cout << b, 0;
    cout << 0;
}