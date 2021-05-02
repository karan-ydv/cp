#include <bits/stdc++.h>
// #define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int ans = 0;
        int n, k;  cin >> n >> k;
        int a[n];   for(int &x: a)  cin >> x;
        if(n == 1)
        {
            double p = k - 1;
            p /= k;
            cout << "Case #" << _ << ": " << p << '\n';
            continue;
        }
        sort(a, a + n);
        ans = max(ans, a[0] - 1);
        ans = max(ans, k - a[n - 1]);
        // cerr << ans << '\n';
        vector<int> v = {a[0] - 1, k - a[n - 1]};
        for(int i = 1; i < n; i++) {
            v.emplace_back(max(0, (a[i] - a[i - 1]) / 2));
            ans = max(ans, max(0, (a[i] - a[i - 1]) / 2));
            ans = max(ans, a[i] - a[i - 1] - 1);
        }
        for(int i = 0; i < v.size(); i++)
        for(int j = i + 1; j < v.size(); j++)
        {
            ans = max(ans, v[i] + v[j]);
        }
        double p = 1.0 * ans / k;
        cout << "Case #" << _ << ": " << p << '\n';
    }
}