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
        if(n & 1)
        {
            if(a[1] + a[0] != 0)
            {
                cout << -a[2] << ' ';
                cout << -a[2] << ' ';
                cout << a[0] + a[1] << ' ';
            }
            else if (a[1] + a[2] != 0)
            {
                cout << a[1] + a[2] << ' ';
                cout << -a[0] << ' ';
                cout << -a[0] << ' ';
            }
            else
            {
                cout << -a[1] << ' ';
                cout << a[0] + a[2] << ' ';
                cout << -a[1] << ' ';
            }
        }
        for(int i = (n & 1 ? 3 : 0); i < n; i += 2)
            cout << a[i + 1] << ' ' << -a[i] << ' ';
        cout << '\n';
    }
}