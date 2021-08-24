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
        int n;	cin >> n;
        int c1, c2;
        c1 = c2 = n / 3;
        if(n % 3 == 0);
        else if(n % 3 == 1) c1++;
        else                c2++;
        cout << c1 << ' ' << c2 << '\n';
    }
}