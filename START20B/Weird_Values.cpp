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
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            if(mp[x].empty())
                mp[x].emplace_back(-1);
            mp[x].emplace_back(i);
        }
        int ans = 0;
        for(auto &[x, v]: mp) {
            int m = (int) v.size();
            v.emplace_back(n);
            for(int j = x; j < m; j++)
                ans += x * (v[j + 1] - v[j]) * (v[j - x + 1] - v[j - x]);
        }
        cout << ans << '\n';
    }
}