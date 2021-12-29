#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    pair<int, int> c[m];
    for(auto &[x, y]: c)    cin >> y >> x;
    sort(c, c + m);
    int g = n, p = n;
    long long ans = 0;
    for(int i = 0; i < m; i++, p = g)
    {
        g = gcd(g, c[i].second);
        ans += (long long) c[i].first * (p - g);
    }
    if(g > 1) ans = -1;
    cout << ans;
}