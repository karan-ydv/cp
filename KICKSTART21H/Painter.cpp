#include <bits/stdc++.h>
#define int int64_t
using namespace std;

map<char, vector<char>> mp
{
    {'R', {'R'}},
    {'Y', {'Y'}},
    {'B', {'B'}},
    {'O', {'R', 'Y'}},
    {'P', {'R', 'B'}},
    {'G', {'Y', 'B'}},
    {'A', {'R', 'Y', 'B'}},
    {'U', {}}
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        string s; int n;
        cin >> n >> s;
        int ans = 0;
        map<char, bool> p;
        for(int i = 0; i < n; i++)
        {
            for(char c: mp[s[i]])
                if(!p[c])   ans++;
            p.clear();
            for(char c: mp[s[i]])
                p[c] = 1;
        }
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}