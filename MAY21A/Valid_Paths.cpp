#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    int V, E, ans;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    int DFS(int u = 0, int p = -1)
    {
        int c = 0;
        vector<int> a;
        for(auto v: adj[u])
        if(v != p)
        {
            int x = DFS(v, u);
            a.emplace_back(x);
            (c += x) %= mod;
        }
        for(int n: a)
        {
            (ans += n * (c - n + mod)) %= mod;
        }
        return (2 * c + 1) % mod;
    }
    void solve()
    {
        ans = 0;
        (ans += DFS()) %= mod;
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
        int n;	cin >> n;
        Graph g(n, n - 1);
        g.solve();
    }
}