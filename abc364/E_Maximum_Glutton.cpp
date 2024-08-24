#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y; cin >> n >> x >> y;

    vector<pair<int, int>> a(n);
    for (auto &[w, c] : a) cin >> w >> c;

    sort(a.begin(), a.end());

    int ans = 1;
    for (int l = 0; l < n; l++)
    {
        int sum = 0;
        for (int r = l; r < n and sum <= x; r++)
        {
            sum += a[r].first;
            if (sum > x) break;
            vector<int> v;
            for (int i = l; i <= r; i++)
                v.push_back(a[i].second);

            sort(v.begin(), v.end());

            int cur = 0, saltiness = 0;
            for (; cur < v.size(); cur++)
            {
                if (saltiness + v[cur] > y) break;
                saltiness += v[cur];
            }
            ans = max(ans, min(n, cur + 1));
        }
    }

    cout << ans << '\n';
}