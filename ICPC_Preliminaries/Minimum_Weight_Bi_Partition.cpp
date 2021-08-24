#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct DSU
{
    vector<int> parent, weight;
    DSU(int n) {
        parent.resize(n + 1);
        weight.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if(parent[x] == x)    return x;
        return parent[x] = find(parent[x]);
    }
    void UNION(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(weight[x] > weight[y]) swap(x, y);
        if(x != y)
        {
            parent[x] = y;
            weight[y] += weight[x];
        }
    }
};

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> A;
    vector<bool> vis;
    vector<pair<int, int>> edges;
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v + 1);
        A.resize(v + 1);
        for(int i = 1; i <= v; i++)
            cin >> A[i];
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u, vector<tuple<int, int, int>> &vv, int c)
    {
        vis[u] = 1;
        vv.emplace_back(A[u], u, c);
        for(int v: adj[u]) if(!vis[v])
        {
            edges.emplace_back(u, v);
            DFS(v, vv, c);
        }
    }
    void solve()
    {
        vis.resize(V + 1);
        vector<tuple<int, int, int>> v;
        int k = 0;
        for(int i = 1; i <= V; i++)
            if(!vis[i]) DFS(i, v, ++k);
        sort(v.begin(), v.end());
        
        vector<tuple<int, int, int, int, int>> edg;
        for(int i = 1; i < v.size(); i++)
        {
            auto [x, y, z] = v[i - 1];
            auto [a, b, c] = v[i];
            if(c != z)
            edg.emplace_back(abs(a-x), c, z, y, b);
        }
        DSU dsu(k);
        int ans = 0;
        sort(edg.begin(), edg.end());
        for(auto [a, b, c, d, e]: edg)
        {
            if(dsu.find(b) != dsu.find(c)) {
                edges.emplace_back(d, e);
                ans += a;
                dsu.UNION(b, c);
            }
        }

        cout << ans << ' ' << edges.size() << '\n';
        for(auto [u, v]: edges)
            cout << u << ' ' << v << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        Graph g(n, m);
        g.solve();
    }
}