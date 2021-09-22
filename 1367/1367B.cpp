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
        int a[n];   for(int &x: a)  cin >> x;
        int x = 0, y = 0;
        for(int i = 0; i < n; i += 2) x += a[i] & 1;
        for(int i = 1; i < n; i += 2) y += !(a[i] & 1);
        if(x == y)
            cout << x << '\n';
        else
            cout << "-1\n";
    }
}