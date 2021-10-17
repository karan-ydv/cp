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
        int a, b, c;    cin >> a >> b >> c;
        int x = max({a, b, c});
        if(a == x)
        {
            if(b != x and c != x)
                cout << "0 ";
            else
                cout << "1 ";
        }
        else
            cout << x + 1 - a << ' ';
        if(b == x)
        {
            if(c != x and a != x)
                cout << "0 ";
            else
                cout << "1 ";
        }
        else
            cout << x + 1 - b << ' ';
        if(c == x)
        {
            if(b != x and a != x)
                cout << "0";
            else
                cout << "1";
        }
        else
            cout << x + 1 - c;
        cout << '\n';
    }
}