#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b)
        return cout << "=", 0;
    if(c & 1)
    {
        if(a > b)
            cout << ">";
        else
            cout << "<";
    }
    else
    {
        a = abs(a), b = abs(b);
        if(a == b)
            cout << "=";
        else if(a > b)
            cout << ">";
        else
            cout << "<";
    }
}