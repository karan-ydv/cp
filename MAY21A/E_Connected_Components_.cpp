#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

struct Graph 
{
    typedef int item;
    vector<set<int>> adj;
    int V, E;
    bitset<N> unv;
    vector<bool> vis;
    Graph(int v, int e) 
    {
        unv.set();
        V = v, E = e;
        adj.resize(v + 1);
        for(int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }
    int DFS(int u)
    {
        unv[u] = 0;
        int c = 1;
        for(int v = unv._Find_first(); v < V; v = unv._Find_next(v))
        if(adj[u].find(v) == adj[u].end())
        {
            c += DFS(v);
        }
        return c;
    }
    void solve()
    {
        vector<int> ans;
        for(int i = 0; i < V; i = unv._Find_next(i))
            ans.emplace_back(DFS(i));
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(int x: ans) cout << x << ' ';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    Graph g(n, m);
    g.solve();
}