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
        int n, m;   cin >> n >> m;
        pair<int, int> a[m];
        for(auto &[x, y]: a)
            cin >> x >> y;
        sort(a, a + m, greater<pair<int, int>>());
        int ans = 0, l = 1;
        for(auto [x, y]: a)
        {
            int temp = lcm(l, y);
            ans += (n / l - n / temp) * x;
            l = temp;
            if(l > n) break;
        }
        cout << ans << '\n';
    }
}