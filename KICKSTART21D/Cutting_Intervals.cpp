#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int n, c;   cin >> n >> c;
        pair<int, int> a[n];
        vector<int> v;
        for(auto &[l, r]: a)
        {
            cin >> l >> r;
            v.emplace_back(l);
            v.emplace_back(r);
            l++, r--;
            v.emplace_back(l);
            v.emplace_back(r);
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        unordered_map<int, int> idx;
        for (int i = 0; i < v.size(); i++)
            idx[v[i]] = i + 1;
        
        int diff[v.size() + 2] = {};
        int pref[v.size() + 2] = {};

        for(auto [l, r]: a) if(l <= r)
        {
            diff[idx[l]] += 1;
            diff[idx[r] + 1] -= 1;
        }

        for(int i = 1; i <= v.size(); i++) {
            pref[i] = pref[i - 1] + diff[i];
        }
        for(int x: v)   cerr << x << ' ';  cerr << '\n';
        for(int x: diff) cerr << x << ' '; cerr <<'\n';
        for(int x: pref) cerr << x << ' '; cerr <<'\n';

        int ans = n;
        priority_queue<pair<int, int>> heap;
        for(int i = 0; i + 1 < v.size(); i++) {
            heap.push({pref[i + 1], v[i + 1] - v[i]});
            // cerr << pref[i + 1] << " " << v[i + 1] - v[i] << '\n';
        }
        heap.push({pref[v.size()], 1});
        while(c and !heap.empty())
        {
            auto [x, f] = heap.top();
            heap.pop();
            ans += x * min(f, c);
            c -= min(f, c);
        }
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}