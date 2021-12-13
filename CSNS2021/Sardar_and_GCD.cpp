#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj, cdrn;
    vector<int> a, g, s;
    int V, E, ans;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        cdrn.resize(v + 1);
        a.resize(v + 1);
        g.resize(v + 1);
        s.resize(v + 1);
        for(int i = 0; i < e; i++)
        {
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for(int i = 1; i <= v; i++)
            cin >> a[i];
        ans = 0;
        dfs(1, 0);
    }
    void dfs(int u, int p)
    {
        for(int v: adj[u]) if(v != p) {
            cdrn[u].emplace_back(v);
            dfs(v, u);
        }
    }
    void dfs1(int u)
    {
        g[u] = a[u];
        for(int v: cdrn[u])
        {
            dfs1(v);
            g[u] = gcd(g[u], g[v]);
            s[u] += g[v];
        }
    }
    void dfs2(int u, int x)
    {
        int n = cdrn[u].size();
        vector<int> d;
        for(int v: cdrn[u])
            d.emplace_back(g[v]);
        d.emplace_back(0);

        for(int i = n - 1; i > 0; i--)
            d[i] = gcd(d[i], d[i + 1]);
        
        int prefGcd = 0;
        for(int i = 0; i < n; i++)
        {
            int y = gcd(prefGcd, d[i + 1]);
            y = gcd(y, gcd(x, a[u]));
            // clog << cdrn[u][i] << " : " << y << ' ' << s[cdrn[u][i]] << '\n';
            ans = max(ans, y + s[cdrn[u][i]]);
            dfs2(cdrn[u][i], gcd(y, a[cdrn[u][i]]));
            prefGcd = gcd(prefGcd, d[i]);
        }
    }
    int solve()
    {
        if(V == 1)
            return 0;
        dfs1(1);
        ans = s[1];
        dfs2(1, 0);
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        Graph g(n, n - 1);
        cout << g.solve() << '\n';
    }
}