#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int ans = 0;
        int d, n, k;    cin >> d >> n >> k;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            int h, s, e;    cin >> h >> s >> e;
            v.emplace_back(s, h);
            v.emplace_back(e + 1, -h);
        }
        sort(v.begin(), v.end());
        int sum = 0;
        multiset<int> set, set2;
        for(auto [x, h]: v)
        {
            if(h > 0)
            {
                sum += h;
                set.insert(h);
                if(set.size() > k)
                {
                    auto itr = set.begin();
                    sum -= *itr;
                    set2.insert(*itr);
                    set.erase(itr);
                }
            }
            else
            {
                auto itr = set.find(-h);
                if(itr != set.end())
                {
                    sum += h;
                    set.erase(itr);
                    if(!set2.empty())
                    {
                        itr = set2.end();
                        sum += *--itr;
                        set.insert(*itr);
                        set2.erase(itr);
                    }
                }
                else
                {
                    itr = set2.find(-h);
                    set2.erase(itr);
                }
            }
            ans = max(ans, sum);
        }
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}