#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<pair<int, int>> edge;
    vector<int> latency;
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v + 1);
        latency.resize(v + 1);
        edge.resize(e);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            edge[i] = {u, v};
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    int BFS(item x)
    {
        queue<pair<item, int>> q;
        unordered_set<item> visited;
        q.push({0, 0});
        while(!q.empty())
        {
            auto [u, d] = q.front();
            q.pop();
            visited.insert(u);
            for(auto v: adj[u])
            {
                if(v == x)	return d + 1;
                if(!visited.count(u)); {
                    q.push({v, d + 1});
                }
            }
        }
        return -1;
    }
    int DFS(int u = 0, int p = -1, int h = 0)
    {
        int c = 0;
        for(auto v: adj[u])
        if(v != p)
        {
            c += DFS(v, u, h + 1);
        }
        return c;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int ans;
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}