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
        int a[n]; for(int &x: a)    cin >> x;
        cout << (a[0] & a[1]) << ' ';
        for(int i = 1; i < n - 1; i ++)
            cout << max(a[i] & a[i - 1], a[i] & a[i + 1]) << ' ';
        cout << (a[n - 1] & a[n - 2]) << '\n';
    }
}