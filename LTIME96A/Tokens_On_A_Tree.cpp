#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree
{
    typedef pair<int, int> node;
    int n;
    vector<node> t;
    Segtree() {}
    Segtree(int n)
    {
        this->n = n;
        t.resize(n << 1);
        for (int i = 0; i < n; i++)
            t[n + i] = {-1, i};
    }
    void build()
    {
        for (int i = n - 1; i > 0; i--)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }
    node range_max(int l, int r)
    { // max on interval [l, r)
        node res = {-1, 0};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = max(res, t[l++]);
            if (r & 1)
                res = max(res, t[--r]);
        }
        return res;
    }
    void modify(int p, int value)
    { // set value at position p
        for (t[p += n].first = value; p > 1; p >>= 1)
            t[p >> 1] = max(t[p], t[p ^ 1]);
    }
};

struct Graph
{
    typedef int item;
    vector<vector<item>> children;
    vector<int> traversal, idx, treesize;
    int V, E, ans;
    string s;
    Segtree sgt;
    Graph(int v)
    {
        V = v;
        idx.resize(v);
        children.resize(v);
        treesize.resize(v);
        sgt = Segtree(v);
        cin >> s;
        for (int i = 1; i < v; i++)
        {
            int x;
            cin >> x;
            children[x - 1].emplace_back(i);
        }
    }
    int DFS(int u = 0, int h = 0)
    {
        idx[u] = traversal.size();
        traversal.emplace_back(u);
        if (s[u] == '1')
        {
            sgt.t[sgt.n + idx[u]].first = h;
            ans += h;
        }
        int c = 1;
        for (int v : children[u])
            c += DFS(v, h + 1);
        return treesize[u] = c;
    }
    int DFS2(int u = 0, int h = 0)
    {
        if (children[u].size() == 0)
        {
            if (s[u] == '0')
                return 0;
            return h;
        }
        int c = 0;
        for (int v : children[u])
            c += DFS2(v, h + 1);
        if (s[u] == '0')
        {
            auto [a, b] = sgt.range_max(idx[u], idx[u] + treesize[u]);
            if (a != -1)
            {
                c += h - a;
                sgt.modify(b, -1);
                sgt.modify(idx[u], h);
            }
        }
        else
            c += h;
        return c;
    }
    int moves()
    {
        ans = 0;
        DFS();
        sgt.build();
        int x = DFS2();
        return ans - x;
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
        int n;
        cin >> n;
        Graph g(n);
        cout << g.moves() << '\n';
    }
}