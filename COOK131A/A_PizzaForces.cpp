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
        n = max(n, (int)6);
        n += n & 1;
        int ans = n / 2 * 5;
        cout << ans << '\n';
    }
}