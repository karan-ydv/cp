#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    return (a <= e and b + c <= d) or
           (b <= e and a + c <= d) or
           (c <= e and a + b <= d);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}