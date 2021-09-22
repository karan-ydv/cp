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
    vector<int> first;
    int V, E;   Segtree st;
    Graph(int v) : V(v)
    {
        adj.resize(v);
        first.resize(v);
        euler.reserve(2 * v - 1);
        for(int i = 0; i < v; i++)
        {
            int m;  cin >> m;
            for(int j = 0; j < m; j++) {
                int x;  cin >> x;
                adj[i].emplace_back(x);
            }
        }
        dfs(0, 0);
        st = Segtree(euler);
    }
    void dfs(int u, int d)
    {
        first[u] = euler.size();
        euler.emplace_back(d, u);
        for(int v: adj[u])
        {
            dfs(v, d + 1);
            euler.emplace_back(d, u);
        }
    }
    int lca(int u, int v)
    {
        if(first[u] > first[v]) swap(u, v);
        return st.range_op(first[u], first[v] + 1).second;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    Graph g(n);
    int q;  cin >> q;
    while(q--)
    {
        int u, v;
        cout << g.lca(u, v) << '\n';
    }
}