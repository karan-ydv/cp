#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        cout << "0 ";
        for(int i = 1, x = a[0]; i < n; i++)
        {
            x = (x ^ a[i]) & x;
            cout << x << ' ';
            x ^= a[i];
        }
        cout << '\n';
    }
}