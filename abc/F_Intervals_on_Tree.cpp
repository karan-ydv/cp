#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0; cin >> n;

    for(int i = 1; i <= n; i++)
        ans += i * (n - i + 1);

    for(int _ = 1; _ < n; _++)
    {
        int u, v;   cin >> u >> v;
        if(u > v) swap(u, v);
        ans -= u * (n - v + 1);
    }

    cout << ans << '\n';
}