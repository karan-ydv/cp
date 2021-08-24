#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("icpc_teams.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    int c = 0;
    map<string, int> mp;
    while(getline(cin, s))
    {
        string t = "";
        for(char c: s)
        {
            if(isalpha(c)) t.push_back(tolower(c));
            else if(c == ' ' and t.back() != ' ')
                t.push_back(c);
        }
        mp[t]++;
    }
    vector<pair<int, string>> v;
    for(auto [college, count]: mp) {
        v.emplace_back(count, college);
    }
    sort(v.rbegin(), v.rend());
    for(auto [count, college]: v) {
    // for(auto [college, count]: mp) {
        cout << setw(100) << college;
        cout << " " << count << "\n";
    }
}