#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    a.emplace_back(1 << 30);
    sort(a.begin(), a.end());

    auto count = [&](int b, int x) -> int
    {
        int r = upper_bound(a.begin(), a.end(), b + x) - a.begin();
        int l = lower_bound(a.begin(), a.end(), b - x) - a.begin();
        return r - l;
    };

    while (q--)
    {
        int b, k; cin >> b >> k;
        int l = 0, r = 2e8;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (count(b, m) >= k)
                ans = m, r = m - 1;
            else
                l = m + 1;
        }
        cout << ans << '\n';
    }
}