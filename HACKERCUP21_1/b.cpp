#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    map<char, int> mp;
    char prev = '!';
    int cnt;
    pair<int, char> ans = {0, '!'};
    for(char c: s)
    {
        if(c != prev)
            cnt = 0;
        cnt++;
        mp[c]++;
        ans = max(ans, {cnt, c});
        prev = c;
    }
    for(auto [x, f]: mp)
        cout << "team " << x << ": " << f << '\n';
    cout << "Team " << ans.second << ' ' << "scored " << ans.first;
}