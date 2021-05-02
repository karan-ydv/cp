#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph {
    typedef int item;
    typedef vector<vector<item>> vv;
    vv adj;
    int n;
    vector<int> d, U, ans;
    Graph(int v, int e) {
        n = v;
        adj.resize(v + 1);
        while(e--)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    int DFS(int u = 0, int p = -1, int h = 0)
    {
        int c = 0;
        for(auto v: adj[u])
        if(v != p)
        {
            int x = DFS(v, u, h + 1);
            if(c == 0)  c = x;
        }
        if(c == 0 and U[u]) c = u;
        if(c != 0)
        {
            ans[u] = h;
            U[u] = c;
        }
        return c;
    }
    void DFS2(int u = 0, int p = -1)
    {
        for(auto v: adj[u])
        if(v != p)
        {
            if(U[v] == 0)
            {
                U[v] = U[U[u]];
                ans[v] = ans[u] - 1;
            }
            DFS2(v, u);
        }
    }
    void solve(vector<int> &v, int a)
    {
        U.resize(n + 1, 0);
        ans.resize(n + 1);
        for(int x: v)   U[x] = x;
        DFS(a);
        DFS2(a);
        for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
        for(int i = 1; i <= n; i++) cout << U[i] << " \n"[i == n];
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k, a;    cin >> n >> k >> a;
        vector<int> v(k);
        for(int &x: v)   cin >> x;
        Graph g(n, n - 1);
        // for(int x: v)   cerr << x << ' ';cerr << '\n';
        g.solve(v, a);
    }
}