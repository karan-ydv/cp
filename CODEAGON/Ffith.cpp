#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int, int> in, out;
    vector<pair<int, int>> ans;
    unordered_map<int, int> adj;
    int n;  cin >> n;
    for(int i = 0; i < n; i++) {
        int x;  cin >> x;
        cin.get(); cin.get();
        string s, t = "";
        getline(cin, s);
        in[x]++;
        int y = 0;
        for(char c: s)
        {
            if(isdigit(c)) {
                y = y * 10 + (c - '0');
            }
            else
            {
                if(!adj.count(x))
                {
                    adj[x] = y;
                }
                out[y]++;
                y = 0;
            }
        }
        if(!adj.count(x))
        {
            adj[x] = y;
        }
        out[y]++;
        y = 0;
    }
    for(auto &[x, y]: adj)
    {
        if(in[x] == 1 and out[x] == 1)
            ans.emplace_back(x, adj[x]);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(auto [a, b]: ans)
        cout << a << '-' << b << '\n';
}