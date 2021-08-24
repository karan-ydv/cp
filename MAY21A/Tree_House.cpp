#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
struct Graph
{
    typedef int item;
    vector<vector<item>> adj;
    int V, E;
    Graph(int v, int e)
    {
        V = v, E = e;
        adj.resize(v + 1);
        while(e--)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    pair<double, int> DFS(int u, int p)
    {
        vector<pair<double, int>> c;
        for(auto v: adj[u]) if(v != p)
            c.emplace_back(DFS(v, u));

        int s = 1;
        double d = 1;
        sort(c.rbegin(), c.rend());
        for(int i = 0; i < c.size(); i++)
        {
            (s += (i + 1) * c[i].second % mod) %= mod;
            d += (i + 1) * c[i].first;
        }
        return {d, s};
    }
    void solve(int x)
    {
        int ans = x * DFS(1, -1).second % mod;
        cout << ans << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, x;   cin >> n >> x;
        Graph g(n, n - 1);
        g.solve(x);
    }
}