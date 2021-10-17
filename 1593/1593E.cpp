#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void solve(int k)
    {
        if(2 * k > V)  return cout << "0\n", void();
        int ans = V;
        bool removed[V] = {};
        int degree[V] = {};
        set<int> leaves;
        for(int i = 0; i < V; i++) {
            degree[i] = adj[i].size();
            if(degree[i] == 1)  leaves.insert(i);
        }
        for(int i = 0; i < k; i++) {
            ans -= leaves.size();
            set<int> set;
            for(int lf: leaves)
            {
                removed[lf] = 1;
                for(int u: adj[lf]) if(!removed[u])
                {
                    degree[u]--;
                    if(degree[u] == 1) set.insert(u);
                }
            }
            leaves.swap(set);
        }
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
        int n, k;   cin >> n >> k;
        Graph g(n, n - 1);
        g.solve(k);
    }
}