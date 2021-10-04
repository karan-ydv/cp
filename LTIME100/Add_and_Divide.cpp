#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve()
{
    int a, b;   cin >> a >> b;
    int x = 1;
    for(int i = 0; i < 30; i++)
        (x *= b) %= a;
    return x == 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
}