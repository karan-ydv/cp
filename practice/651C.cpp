#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    map<int, int> x, y;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++) {
        int a, b;   cin >> a >> b;
        x[a]++, y[b]++;
        mp[{a, b}]++;
    }
    int ans = 0;
    for(auto [v, f]: x) {
        ans += f * (f - 1) / 2;
    }
    for(auto [v, f]: y) {
        ans += f * (f - 1) / 2;
    }
    for(auto [v, f]: mp) {
        ans -= f * (f - 1) / 2;
    }
    cout << ans << '\n';
}