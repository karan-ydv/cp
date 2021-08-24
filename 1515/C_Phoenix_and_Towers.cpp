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
        int n, m, x;    cin >> n >> m >> x;
        int c = 0;
        pair<int, int> a[n];   for(auto &[f, s]: a)  cin >> f, s = c++;
        sort(a, a + n, greater<pair<int, int>>());

        int ans[n];
        set<pair<int, int>> set;
        for(int i = 0; i < m; i++)
        {
            set.insert({a[i].first, i + 1});
            ans[a[i].second] = i + 1;
        }
        
        for(int i = m; i < n; i++)
        {
            auto itr = set.begin();
            auto [x, y] = *itr;
            ans[a[i].second] = y;
            x += a[i].first;
            set.erase(itr);
            set.insert({x, y});
        }
        int d = set.rbegin()->first - set.begin()->first;
        if(d > x)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(int x: ans) cout << x << ' ';
            cout << '\n';
        }
    }
}