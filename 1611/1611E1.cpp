#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> frn;
    vector<bool> frnd;
    int V, k;
    Graph()
    {
        int v;
        cin >> v >> k;
        V = v;
        adj.resize(v + 1);
        frnd.resize(v + 1);
        frn.resize(v + 1);
        for(int i = 1; i <= k; i++) {
            int x;  cin >> x;
            frnd[x] = 1;
        }
        for(int i = 1; i < v; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1, 0);
        // for(int i = 1; i <= v; i++)
        //     clog << frn[i] << ' ';
        // clog << "\n\n";
    }
    int dfs(int u, int p)
    {
        if(frnd[u]) return frn[u] = 0;
        frn[u] = 1e8;
        for(int v: adj[u]) if(v != p)
            frn[u] = min(frn[u], dfs(v, u) + 1);
        return frn[u];
    }
    bool DFS(int u, int p, int h = 0)
    {
        if(u != 1 and adj[u].size() == 1)
            return h < frn[u];
        if(h >= frn[u]) return false;
        for(int v: adj[u]) if(v != p)
            if(DFS(v, u, h + 1)) return true;
        return false;
    }
    void solve()
    {
        DFS(1, 0) ? cout << "YES\n" : cout << "NO\n";
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        Graph g;
        g.solve();
    }
}