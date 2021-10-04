#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    int V, E, tiktok;
    vector<int> tin, low;
    vector<bool> vis;
    set<int> cutpoints;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        vis.resize(v + 1);
        tin.resize(v + 1, -1);
        low.resize(v + 1, -1);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
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
            if(vis[v])
                low[u] = min(low[u], tin[v]);
            else 
            {
                c++;
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= tin[u] and p != -1)
                    cutpoints.insert(u);
            }
        }
        if(p == -1 and c > 1)
            cutpoints.insert(u);
    }
    int solve()
    {
        tiktok = 0;
        for(int i = 1; i <= V; i++)
            if(!vis[i]) DFS(i, -1);
        return cutpoints.size();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   
    while(cin >> n >> m, n)
    {
        Graph g(n, m);
        cout << g.solve() << '\n';
    }
}