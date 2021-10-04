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
        string s;   cin >> s;
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        int ans = 0, flag = 0;
        for(auto [c, f]: mp) {
            if(f > 1) ans++;
            else
            {
                ans += flag;
                flag ^= 1;
            }
        }
        cout << ans << '\n';
    }
}