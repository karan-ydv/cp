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
        pair<int, int> p[n];
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            p[i].first = a[i];
            p[i].second = i;
        }
        map<int, int> ans;
        sort(p, p + n);
        for(int i = 0; i < n; ) {
            int j, val = 1;
            auto [x, y] = p[i];
            // cerr << i << " : \n";
            for(j = i; j < n and p[j].first == p[i].first; j++) {
                // cerr << j << ' ' << n - j - 1 << '\n';
                val = max(val, 1 + 2 * min(j, n - j - 1));
            }
            ans[x] = val;
            i = j;
        }
        for(int x: a)
            cout << ans[x] << ' ';
        cout << '\n';
        // cerr << '\n';
    }
}