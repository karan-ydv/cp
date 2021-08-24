#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    typedef int item;
    vector<vector<item>> adj;
    int V, E;
    vector<bool> visited;
    Graph(int v, int e)
    {
        V = v, E = e;
        adj.resize(v + 1);
        for (int i = 0; i < e; i++)
        {
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
        }
    }
    int DFS(int u)
    {
        visited[u] = 1;
        int c = 1;
        for (auto v : adj[u])
            if (!visited[v])
                c += DFS(v);
        return c;
    }
    void solve()
    {
        int ans = 0;
        for (int i = 1; i <= V; i++)
        {
            visited = vector<bool>(V);
            ans += DFS(i);
        }
        cout << ans << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    g.solve();
}