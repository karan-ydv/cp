#include <bits/stdc++.h>
using namespace std;

// segment tree for the depth of leaves
// of the tree rooted at one end of diamter
struct Segtree
{
    int n, h;
    vector<pair<int, int>> t;
    vector<int> d;
    Segtree(vector<int> &v)
    {
        n = v.size();
        d.resize(n);
        t.resize(n << 1);
        h = 32 - __builtin_clz(n);
        for(int i = 0; i < n; i++)
            t[n + i] = {v[i], i};
        for(int i = n - 1; i > 0; i--)
            t[i] = max(t[i << 1], t[i << 1|1]);
    }

    void apply(int p, int value)
    {
        t[p].first += value;
        if (p < n) d[p] += value;
    }

    void build(int p)
    { // modify value of parents of p
        while (p > 1)
            p >>= 1, t[p] = max(t[p << 1], t[p << 1|1]), t[p].first += d[p];
    }

    void push(int p)
    { // propagate from root to p
        for (int s = h; s > 0; --s)
        {
            int i = p >> s;
            if (d[i] != 0)
            {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }

    void increment(int l, int r, int value)
    { // add v to interval [l, r)
        l += n, r += n;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) apply(l++, value);
            if (r & 1) apply(--r, value);
        }
        build(l0);
        build(r0 - 1);
    }

    pair<int, int> range_max(int l, int r)
    { // max on interval [l, r)
        l += n, r += n;
        push(l); push(r - 1);
        pair<int, int> res = {-1e9, -1e9};
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

struct Graph
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> par, L, R, leaves, node;
    vector<bool> visited;
    int V, E;
    Graph(int v, int e)
    {
        V = v, E = e;
        adj.resize(v + 1);
        par.resize(v + 1);
        L.resize(v + 1);
        R.resize(v + 1);
        visited.resize(V + 1);
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    pair<int, int> Farthest(int u, int p, int h)
    {
        pair<int, int> f = {-1, u};
        for (auto v : adj[u]) if (v != p)
            f = max(f, Farthest(v, u, h + 1));
        f.first++;
        return f;
    }
    void DFS(int u, int p, int h)
    {
        par[u] = p;
        L[u] = leaves.size();
        for (int v : adj[u])
            if (v != p)
                DFS(v, u, h + 1);
        if (leaves.size() == L[u])
        {
            leaves.emplace_back(h);
            node.emplace_back(u);
        }
        R[u] = leaves.size();
    }
    int solve(int k)
    {
        if (k <= 2) return k;
        int root = Farthest(1, 0, 0).second;
        DFS(root, 0, 0);
        // cerr << root << '\n';
        visited[root] = 1;
        int ans, d, f;
        Segtree sg(leaves);
        for(ans = 1; k > 1; ans++, k -= d)
        {
            tie(d, f) = sg.range_max(0, leaves.size());
            f = node[f];
            visited[f] = 1;
            // cerr << f << ' ' << d << '\n';
            sg.increment(L[f], R[f], -V);
            while (!visited[par[f]])
            {
                f = par[f];
                visited[f] = 1;
                sg.increment(L[f], R[f], -1);
            }
        }
        return ans;
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
        int n, k;
        cin >> n >> k;
        Graph g(n, n - 1);
        cout << g.solve(k) << '\n';
    }
}