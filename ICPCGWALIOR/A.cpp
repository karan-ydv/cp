#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> c;
    vector<bool> vis;
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v);
        vis.resize(v);
        c.resize(v);
        for(int &x: c)  cin >> x;
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u, vector<int> &vec)
    {
        vis[u] = 1;
        vec.emplace_back(c[u]);
        for(auto v: adj[u]) if(!vis[v])
        {
            DFS(v, vec);
        }
    }
    void solve()
    {
        int ans = 0;
        for(int i = 0; i < V; i++) if(!vis[i]) {
            vector<int> v;
            DFS(i, v);
            sort(v.begin(), v.end());
            ans += accumulate(v.begin(), v.end(), 0ll);
            // cerr << v.size() << '\n';
            for(int i = 0; i < v.size() / 2; i++) {
                ans += v[i] - v[v.size() - 1 - i];
            }
        }
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
        int n, m;   cin >> n >> m;
        Graph g(n, m);
        g.solve();
    }
}