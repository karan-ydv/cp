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
        vector<int> v[n];
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            auto &[u, k] = a[i];
            cin >> k;
            v[i].resize(k);
            for(int j = 0; j < k; j++) {
                cin >> v[i][j];
                u = max(u, v[i][j] - j);
            }
            // u++;
        }
        sort(a.begin(), a.end());
        int ans = 0, sum = 0;
        for(auto [enter, k]: a)
        {
            ans = max(ans, enter - sum);
            sum += k;
        }
        cout << ++ans << '\n';
    }
}