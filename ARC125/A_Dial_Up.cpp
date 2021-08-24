#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int &x: a)  cin >> x;
    for(int &x: b)  cin >> x;

    if(find(b, b + m, 1) - b < m and find(a, a + n, 1) - a == n)
        return cout << -1, 0;
    if(find(b, b + m, 0) - b < m and find(a, a + n, 0) - a == n)
        return cout << -1, 0;

    int ans = m, x = 1e9;
    for(int i = 1; i < n; i++)
    if(a[i] != a[0])
        x = min({x, i, n - i});
    
    for(int i = 0; i < m; i++)
    if(b[i] != a[0])
    {
        ans += x;
        break;
    }
    int p = find(b, b + m, 1 - a[0]) - b + 1;
    for(int i = p; i < m; i++)
        ans += b[i] != b[i - 1];
    cout << ans << '\n';
}