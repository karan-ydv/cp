#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    if(n & 1)
    {
        for(int i = 0; i < n; i++)
            cout << i << ' ';
        cout << '\n';
        for(int i = 0, x = n - 1; i < n; i++, (x += n - 2) %= n)
            cout << x << ' ';
        cout << '\n';
        for(int i = 0, x = n - 1; i < n; i++, (x += n - 2) %= n)
            cout << (i + x) % n << ' ';
    }
    else cout << "-1";
}