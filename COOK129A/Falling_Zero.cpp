#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> val, dp;
    int V, E, ans;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v + 1);
        val.resize(v + 1);
        dp.resize(v + 1);
        for(int i = 1; i <= v; i++)
            cin >> val[i];
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u = 1, int p = 0, int last = 0)
    {
        (dp[u] = 1 + dp[last]) %= mod;
        if(adj[u].size() == 1)
        {
            (ans += dp[u]) %= mod;
        }
        for(auto v: adj[u])
        if(v != p)
        {
            DFS(v, u, (val[u] == val[v]) ? last : u);
        }
    }
    void solve()
    {
        if(V == 1)  return cout << "1\n", void();
        ans = 0;
        DFS();
        cout << ans << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        Graph g(n, n - 1);
        g.solve();
    }
}