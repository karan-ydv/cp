#include <bits/stdc++.h>
using namespace std;

struct Graph {
    typedef int item;
    typedef vector<vector<item>> vv;
    vv adj;
    vector<int> deg;
    int n;
    vector<tuple<int, int>> op;
    int leaf;
    vector<int> leaff;
    Graph(int v, int e)
    {
        n = v;
        adj.resize(v + 1);
        deg.resize(v + 1);
        leaff.resize(v + 1);
        while(e--)
        {
            int u, v;	cin >> u >> v;
            deg[u] += 1; deg[v] += 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    vector<int> diameter(int U, int P, int h = 0)
    {
        int mx = -1;
        int A, B;
        function<void(int, int, int)> dfs1 = [&](int u, int p, int h)
        {
            for(auto v: adj[u])
            if(v != p and v != P)
                dfs1(v, u, h + 1);
            if(h > mx)
                mx = h, A = u;
        };
        dfs1(U, P, 0);
        mx = -1, swap(A, B);
        dfs1(B, -1, 0);
        cout << A << ' ' << B << '\n';
        vector<int> d;
        function<bool(int, int)> dfs2 = [&](int u, int p)
        {
            bool f = false;
            for(auto v: adj[u])
            if(v != p and v != P)
            {
                f |= dfs2(v, u);
            }
            f |= (u == B);
            if(f)    d.emplace_back(u);
            return f;
        };
        dfs2(A, -1);
        return d;
    }
    void DFS(int u = 0, int p = -1)
    {
        int c = 0;
        if(adj[u].size() == 1)
        {
            leaff[u] = u;
        }
        for(auto v: adj[u])
        if(v != p)
        {
            DFS(v, u);
        }
        if(p != -1)
        if(deg[p] > 2)
        {
            deg[p]--;
            op.emplace_back(u, p);
        }
        else if(deg[u] == 1)    leaf = u, leaff[p] = leaff[u];
    }
    void solve()
    {
        for(int x: diameter(1, -1, 0))
            cout << x << ' ';
        // DFS(1);
        // int ans = op.size();
        // cout << ans << '\n';
        // if(ans)
        // for(auto [a, b]: op)
        // {
        //     cout << a << ' ' << b << ' ' << a << ' ' << leaf << '\n';
        //     leaf = leaff[a];
        // }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        Graph g(n, n - 1);
        g.solve();
    }
}