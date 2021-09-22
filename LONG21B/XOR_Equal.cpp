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
        int n, k;   cin >> n >> k;
        map<int, int> mp;
        int a[n];   for(int &x: a)  cin >> x, mp[x]++;
        pair<int, int> ans = {-1e9, -1e9};
        for (auto [x, f]: mp)
            ans = max(ans, {f, 0});

        if(k != 0)
        for (auto [x, f]: mp)
            ans = max(ans, {f + mp[x ^ k], -mp[x ^ k]});
        cout << ans.first << ' ' << -ans.second << '\n';
    }
}