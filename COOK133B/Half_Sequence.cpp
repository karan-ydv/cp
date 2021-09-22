#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;  cin >> n;
    int m = (n + 1) / 2;
    int gcd = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(x % 2 == 0 and cnt < m)
        {
            gcd = __gcd(gcd, x / 2);
            cnt++;
        }
    }
    if(cnt < m) return false;
    return gcd == 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
}