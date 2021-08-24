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
        unordered_map<int, vector<int>> mp;
        int a[n], ans[n] = {};
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            mp[x].emplace_back(i);
        }
        
        vector<int> v;
        for(auto &[c, f]: mp)
        {
            if(f.size() >= k)
            {
                for(int i = 0; i < k; i++)
                    ans[f[i]] = i + 1;
            }
            else
            {
                if(v.size() + f.size() < k)
                    v.insert(v.end(), f.begin(), f.end());
                else
                {
                    int cnt = 0;
                    for(int x: v) ans[x] = ++cnt;
                    while(cnt < k)
                    {
                        ans[f.back()] = ++cnt;
                        f.pop_back();
                    }
                    v.swap(f);
                }
            }
        }
        for(int x: ans) cout << x << ' '; cout << '\n';
    }
}