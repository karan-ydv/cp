#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> L, R, dp[2];
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v);
        L.resize(v); R.resize(v);
        dp[0].resize(v); dp[1].resize(v);
        for(int i = 0; i < v; i++)
            cin >> L[i] >> R[i];
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u = 0, int p = -1)
    {
        for(auto v: adj[u]) if(v != p)
        {
            DFS(v, u);
            dp[0][u] += max(abs(L[u] - L[v]) + dp[0][v], abs(L[u] - R[v]) + dp[1][v]);
            dp[1][u] += max(abs(R[u] - L[v]) + dp[0][v], abs(R[u] - R[v]) + dp[1][v]);
        }
    }
    void solve()
    {
        DFS();
        cout << max(dp[0][0], dp[1][0]) << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        Graph g(n, n - 1);
        g.solve();
    }
}