#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    int V, tiktok;
    vector<int> tin, low;
    vector<bool> vis;
    set<int> cutpoints;
    Graph(vector<vector<int>> &v)
    {
        V = v.size() - 1;
        adj.resize(V + 1);
        vis.resize(V + 1);
        tin.resize(V + 1, -1);
        low.resize(V + 1, -1);
        adj.swap(v);
    }
    void DFS(int u, int p)
    {
        vis[u] = 1;
        tin[u] = low[u] = tiktok++;
        int c = 0;
        for(auto v: adj[u]) if(v != p)
        {
            if(vis[v])
                low[u] = min(low[u], tin[v]);
            else 
            {
                c++;
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= tin[u] and p != -1)
                    cutpoints.insert(u);
            }
        }
        if(p == -1 and c > 1)
            cutpoints.insert(u);
    }
    int solve()
    {
        tiktok = 0;
        for(int i = 1; i <= V; i++)
            if(!vis[i]) DFS(i, -1);
        return cutpoints.size();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n, n)
    {
        vector<vector<int>> v(n + 1);
        int k;
        while(cin >> k, k)
        {
            int x;
            while(cin >> x)
            {
                v[k].emplace_back(x);
                v[x].emplace_back(k);
                if(cin.peek() == '\n')
                    break;
            }
        }

        Graph g(v);
        cout << g.solve() << endl;
    }
}