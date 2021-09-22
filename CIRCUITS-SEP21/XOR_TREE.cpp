#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    typedef pair<int, int> item;
    int n;  vector<item> t;
    inline item op(item a, item b) { return min(a, b); }
    Segtree() = default;
    Segtree(vector<item>& v) {
        n = v.size();
        t.resize(n << 1);
        copy(v.begin(), v.end(), t.begin() + n);
        for(int i = n - 1; i > 0; i--)
            t[i] = op(t[i << 1], t[i << 1|1]);
    }
    item range_op(int l, int r) {  // op on interval [l, r)
        item res = {1 << 30, 0};    // neutral value
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
};

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<pair<int, int>> euler;
    vector<int> first, value, zor;
    int V, E;   Segtree st;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        zor.resize(v + 1);
        first.resize(v + 1);
        value.resize(v + 1);
        euler.reserve(2 * v - 1);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1, 0, 0);
        st = Segtree(euler);
    }
    void dfs(int u, int p, int d)
    {
        first[u] = euler.size();
        euler.emplace_back(d, u);
        for(int v: adj[u]) if(v != p)
        {
            dfs(v, u, d + 1);
            euler.emplace_back(d, u);
        }
    }
    int lca(int u, int v)
    {
        if(first[u] > first[v]) swap(u, v);
        return st.range_op(first[u], first[v] + 1).second;
    }
    void DFS(int u, int p)
    {
        for(int v: adj[u]) if(v != p) {
            zor[u] ^= zor[v];
            DFS(v, u);
        }
        value[u] ^= zor[u];
    }
    void solve(int q)
    {
        while(q--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            int a = lca(u, v);
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
    int t;	cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        Graph g(n, n - 1);
        g.solve(q);
    }
}