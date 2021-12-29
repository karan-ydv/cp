#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct Graph {
    typedef int item;
    unordered_map<int, vector<item>> adj;
    unordered_map<int, bool> vis, dp;
    unordered_set<int> children;
    int n, a, b;
    Graph(int v) : n(v)
    {
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
        }
        int e;  cin >> e;
        while(e--)
        {
            int u, v, w;
            cin >> u >> v;
            adj[u].emplace_back(v, w);
        }
    }
    bool dfs(int u)
    {
        if(vis[u])  return dp[u];
        vis[u] = true;
        if(u == b)  return dp[u] = true;
        for(int x: adj[u]) {
            if(dfs)
        }
        return dp[u] = false;
    }
    void solve()
    {
        cin >> a >> b;
        vector<int> ans;
        for(int x: adj[a]) {
            vis[x] = true;
            if(x == b)  ans.emplace_back(b);
        }
        for(int x: ans)
    }
};
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Graph g(n);
    g.solve();
}