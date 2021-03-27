#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        vector<int> a[n];
        int b[n], ans = 0;
        unordered_map<int, vector<pair<int, bool>>> mp;
        unordered_set<int> counted;
        for(int i = 0; i < n; i++)
        {
            int m;  cin >> m;
            a[i].resize(m);
            for(int &x: a[i])   cin >> x;
            unordered_set<int> pos, neg;
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] > 0) pos.insert(a[i][j]);
                else            neg.insert(-a[i][j]);
            }
            ans += 1LL * pos.size() * neg.size();
            b[i] = neg.size();
            for(int v: pos) {
                if(neg.count(v))
                {
                    if(counted.count(v))    ans--;
                    else        counted.insert(v);
                }
                else mp[v].push_back({i, 1});
            }
            for(int v: neg) {
                if(!pos.count(v))
                mp[v].push_back({i, 0});
            }
        }
        for(auto x: mp)
        if(x.s.size() > 1 or counted.count(x.f))
        {
            if(!counted.count(x.f)) ans++;
            for(auto [i, pos]: x.s)
            {
                if(pos)
                {
                    int p = b[i] - (lower_bound(a[i].begin(), a[i].begin() + b[i], -x.f) - a[i].begin());
                    int q = upper_bound(a[i].begin() + b[i], a[i].end(), x.f) - a[i].begin();
                    ans += -b[i] + a[i].size() - q + p;
                }
                else
                {
                    int p = lower_bound(a[i].begin(), a[i].begin() + b[i], -x.f) - a[i].begin();
                    int q = (upper_bound(a[i].begin() + b[i], a[i].end(), x.f) - a[i].begin()) - b[i];
                    ans += -a[i].size() + b[i] + q + p;
                }
            }
        }
        cout << ans << '\n';
    }
}