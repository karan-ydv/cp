#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    int diff[n + 2] = {};
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        diff[x]++;
        diff[y + 1]--;
    }
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        diff[i] += diff[i - 1];
        ans += diff[i] == m;
    }
    cout << ans;
}