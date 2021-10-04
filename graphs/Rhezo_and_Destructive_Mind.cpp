#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> tin, low;
    vector<bool> vis, apoint;
    int V, E, tiktok;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u, int p)
    {
        vis[u] = 1;
        tin[u] = low[u] = tiktok++;
        int c = 0;
        for(auto v: adj[u]) if(v != p)
        {
            if(vis[v])  low[u] = min(low[u], tin[v]);
            else {
                c++;
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= tin[u] and p != -1)
                    apoint[u] = 1;
            }
        }
        if(c > 1 and p == -1)
            apoint[u] = 1;
    }
    
    void solve()
    {
        tin.resize(V);
        low.resize(V);
        vis.resize(V);
        apoint.resize(V);
        tiktok = 0;
        for(int i = 0; i < V; i++)
            if(!vis[i]) DFS(i, -1);
        
        int q, x;  cin >> q;
        while(q--)
        {
            cin >> x;
            if(apoint[--x])
                cout << "Satisfied " << adj[x].size() << '\n';
            else
                cout << "Not Satisfied\n";
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    Graph g(n, m);
    g.solve();
}