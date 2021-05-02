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
        int r, b, d;    cin >> r >> b >> d;
        if(r > b)   swap(r, b);
        int x = (b / r) - 1 + (b % r != 0);
        if(x <= d)  cout << "YES\n";
        else        cout << "NO\n";
    }
}