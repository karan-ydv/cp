#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int N = 1e9;
bool solve()
{
    int n;	cin >> n;
    int a[n]; for(int &x: a)    cin >> x;
    for(int i = 0, p = 1; i < n and p <= N; i++)
    {
        p = lcm(p, i + 2);
        clog << p << ' ' << a[i] << '\n';
        if(a[i] % p == 0)   return false;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cerr.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
}