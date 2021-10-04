#include <bits/stdc++.h>
using namespace std;

class LCA
{
    typedef pair<int, int> item;
    int n;
    vector<item> t;
    vector<int> first;
    inline item op(item a, item b) { return min(a, b); }

public:
    LCA(int v, vector<vector<int>> &adj)
    {
        n = 2 * v - 1;
        t.resize(n << 1);
        first.resize(n + 1);
        int c = 0;
        function<void(int, int, int)>
            euler_tour = [&](int u, int p, int h)
        {
            t[n + c] = {h, u};
            first[u] = c++;
            for (int v : adj[u])
                if (v != p)
                {
                    euler_tour(v, u, h + 1);
                    t[n + c++] = {h, u};
                }
        };
        euler_tour(1, 0, 0);
        for (int i = n - 1; i > 0; i--)
            t[i] = op(t[i << 1], t[i << 1 | 1]);
    }
    int lca(int u, int v)
    {
        int l = first[u], r = first[v];
        if (l > r)
            swap(l, r);
        r++;
        item res = {1 << 30, 0};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = op(res, t[l++]);
            if (r & 1)
                res = op(res, t[--r]);
        }
        return res.second;
    }
};

struct Graph
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> value, zor;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u, int p)
    {
        for (int v : adj[u])
            if (v != p)
            {
                DFS(v, u);
                zor[u] ^= zor[v];
            }
        value[u] ^= zor[u];
    }
    void solve(int q)
    {
        LCA L(V, adj);
        zor.resize(V + 1);
        value.resize(V + 1);
        while (q--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            int a = L.lca(u, v);
            zor[u] ^= w;
            zor[v] ^= w;
            value[a] ^= w;
        }
        DFS(1, 0);
        cout << accumulate(value.begin(), value.end(), 0ll) << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        Graph g(n, n - 1);
        g.solve(q);
    }
}