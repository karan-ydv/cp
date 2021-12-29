#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> p;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        p.resize(v + 1);
        for(int i = 1; i <= v; i++)
            cin >> p[i];
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    pair<int, int> dfs(int u, int par)
    {
        int a = 0, b = 0;
        for(int v: adj[u]) if(v != par) {
            auto [x, y] = dfs(v, u);
            a += x, b += y;
        }
        return {max(p[u] + b, a), a};
    }
    int solve()
    {
        return dfs(1, -1).first;
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