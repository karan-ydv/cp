#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> tin, low;
    vector<bool> vis;
    int V, E, a, b, c, tiktok;
    Graph(int v, int e) : V(v), E(e)
    {
        cin >> a >> b;  --a, --b;
        adj.resize(v);
        tin.resize(v);
        low.resize(v);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    bool DFS(int u, int p)
    {
        vis[u] = 1;
        tin[u] = low[u] = tiktok++;
        bool flag = u == b;
        for(auto v: adj[u]) if(v != p)
        {
            if(vis[v])
                low[u] = min(low[u], tin[v]);
            else {
                bool f = DFS(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u]) c += f;
                flag |= f;
            }
        }
        return flag;
    }
    void solve()
    {
        vis.resize(V);
        tiktok = c = 0;
        DFS(a, -1);
        cout << c;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    Graph g(n, m);
    g.solve();
}