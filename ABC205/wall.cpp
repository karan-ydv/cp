#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<pair<double, string>> set;
    int n;  cin >> n;
    map<string, double> mp;
    for(int i = 0; i < n; i++)
    {
        string s;   cin >> s;
        set.insert({i, s});
        mp[s] = i;
    }
    int q;  cin >> q;
    while(q--)
    {
        char op;    cin >> op;
        if(op == 'A')
        {
            if(set.empty())
                continue;
            mp.erase(set.begin()->second);
            set.erase(set.begin());
        }
        else if(op == 'B')
        {
            string s1, s2; cin >> s1 >> s2;
            double idx = mp[s2];
            auto itr = set.upper_bound({idx, s2});
            if(itr == set.end())
                idx += 1;
            else
                idx = (idx + itr->first) / 2;
                
            set.insert({idx, s1});
            mp[s1] = idx;
        }
        else
        {
            string s;   cin >> s;
            if(set.empty())
            {
                set.insert({0, s});
                mp[s] = 0;
            }
            else
            {
                double idx = set.begin()->first - 1;
                set.insert({idx, s});
                mp[s] = idx;
            }
        }
    }
    for(auto [a, b]: set)
        cout << b << ' ';
}