#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef pair<int, int> item;
    vector<vector<int>> adj;
    vector<int> dp, ass;
    // dp[i] = minimum time at which an assasin will reach node i
    // ass = list of assassins
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v + 1);
        dp.resize(v + 1);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    int DFS(int u, int p)
    {
        if(adj[u].size() == 1)
            return dp[u] = 0;
        int mn = 1e9, flg = -1;
        for(auto v: adj[u]) if(v != p)
        {
            int x = DFS(v, u);
            if(x + 1 != mn) ++flg;
            mn = min(mn, x + 1);
        }
        return dp[u] = mn + (flg != 0);
    }
    void DFS2(int u, int p, int day)
    {
        if(day > dp[u]) return;
        for(int v: adj[u]) if(v != p)
        {
            if(day == dp[u])
                DFS2(v, u, day - 1);
            else
                DFS2(v, u, day);
        }
        if(day == 0) ass.emplace_back(u);
    }
    void solve()
    {
        dp[1] = 1e9;
        for(int v: adj[1]) dp[1] = min(dp[1], DFS(v, 1) + 1);
        for(int v: adj[1]) if(dp[v] + 1 == dp[1])  DFS2(v, 1, dp[v]);
        sort(ass.begin(), ass.end());
        cout << ass.size() << ' ' << dp[1] << '\n';
        for(int x: ass) cout << x << ' '; cout << '\n';
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