#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+69;
string s[N];
int vis[N], dp[N];
unordered_map<string, vector<int>> chd;

int dfs(int i)
{
    if(vis[i] == 2) return dp[i];
    if(vis[i] == 1) return -1;
    vis[i] = 1;
    string x = s[i].substr(s[i].size() - 3);
    bool lose = false, draw = false;
    for(int v: chd[x])
    {
        int d = dfs(v);
        draw |= d == -1;
        lose |= d == 1;
    }
    vis[i] = 2;
    if(lose)    return dp[i] = 0;
    if(draw)    return dp[i] = -1;
    return dp[i] = 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        string x = s[i].substr(0, 3);
        chd[x].emplace_back(i);
    }
    
    for(int i = 0; i < n; i++) {
        int x = dfs(i);
        if(x == 1)      cout << "Takahashi\n";
        else if(x == 0) cout << "Aoki\n";
        else            cout << "Draw\n";
    }
}