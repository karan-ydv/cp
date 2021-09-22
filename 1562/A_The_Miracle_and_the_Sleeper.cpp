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
        int l, r;   cin >> l >> r;
        int n = r - l;
        int a = r, b;
        if(r < 2 * l)
            b = l;
        else
        {
            b = (r + 2) / 2;
        }
        cout << a % b << '\n';
    }
}