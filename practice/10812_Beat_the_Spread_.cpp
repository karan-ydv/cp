#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int a, b;   cin >> a >> b;
        int c = (a + b) / 2;
        int d = c - b;
        if(c + c == a + b and d >= 0)
            cout << c  << ' ' << d << '\n';
        else
            cout << "impossible\n";
    }
}