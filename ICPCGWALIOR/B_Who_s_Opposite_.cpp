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
        if(b < a) swap(a, b);
        int n = (b - a) * 2 ;
        if(max({a, b, c}) > n)
            cout << "-1\n";
        else
        {
            n >>= 1;
            if(c <= n)
                cout << c + n << '\n';
            else
                cout << c - n << '\n';
        }
    }
}