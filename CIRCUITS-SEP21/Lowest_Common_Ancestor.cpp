#include <bits/stdc++.h>
using namespace std;

class LCA {
    typedef pair<int, int> item;
    int n;
    vector<item> t;
    vector<int> first;
    inline item op(item a, item b) { return min(a, b); }
public:
    LCA(int v, vector<vector<int>>& adj) {
        n = 2 * v - 1;
        first.resize(n + 1);
        t.resize(n << 1);
        int c = 0;
        function<void(int, int, int)>
        euler_tour = [&](int u, int p, int h)
        {
            t[n + c] = {h, u};
            first[u] = c++;
            for(int v: adj[u]) if(v != p)
            {
                euler_tour(v, p, h + 1);
                t[n + c++] = {h, u};
            }
        };
        euler_tour(0, 0, 0);
        for(int i = n - 1; i > 0; i--)
            t[i] = op(t[i << 1], t[i << 1|1]);
    }
    int lca(int u, int v) {
        int l = first[u], r = first[v];
        if(l > r)   swap(l, r); r++;
        item res = {1 << 30, 0};
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res.second;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++)
    {
        int m;  cin >> m;
        adj[i].resize(m);
        for(int &x: adj[i])
            cin >> x;
    }
    LCA L(n, adj);
    int q;  cin >> q;
    while(q--)
    {
        int u, v;   cin >> u >> v;
        cout << L.lca(u, v) << '\n';
    }
}