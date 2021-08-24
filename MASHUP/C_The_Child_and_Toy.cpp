#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> force;
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v);
        force.resize(v);
        int c = 0;
        for(int &x: force)  cin >> x;
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void solve()
    {
        vector<bool> removed(V);
        int idx[V];
        iota(idx, idx + V, 0);
        sort(idx, idx + V, [&](int x, int y) {
            return force[x] > force[y];
        });
        int64_t ans = 0;
        for(int u: idx)
        {
            for(int v: adj[u])  if(!removed[v]) ans += force[v];
            removed[u] = 1;
        }
        cout << ans;
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