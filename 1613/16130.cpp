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
        long double x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        for(int x = (int) x1; x; x /= 10, x1 /= 10) p1++;
        for(int x = (int) x2; x; x /= 10, x2 /= 10) p2++;
        if(p1 > p2)
            cout << '>';
        else if(p1 < p2)
            cout << '<';
        else
        {
            if(x1 > x2)
                cout << '>';
            else if(x1 < x2)
                cout << '<';
            else
                cout << '=';
        }
        cout << '\n';
    }
}