#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve()
{
    int n;      cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    if(n > 4)   return cout << "NO\n", void();
    cout << "YES\n";
    if(n > 0)   cout << "0 " << a[0] << '\n';
    if(n > 1)   cout << "0 " << -a[1] << '\n';
    if(n > 2)   cout << a[2] << " 0\n";
    if(n > 3)   cout << -a[3] << " 0\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve();
    }
}