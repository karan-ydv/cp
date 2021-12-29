#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct Graph {
    typedef pair<int, int> item;
    unordered_map<int, int> dist;
    unordered_map<int, vector<item>> adj;
    int n;
    Graph(int v) : n(v)
    {
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
        }
        int e;  cin >> e;
        while(e--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u] = dist[v] = 1ll << 60;
            adj[u].emplace_back(v, w);
        }
    }
    void Dijkstra(int a)
    {
        dist[a] = 0;
        unordered_map<int, bool> vis;
        priority_queue<item, vector<item>, greater<item>> q;
        q.push({0, a});
        while(!q.empty())
        {
            int d, u;
            tie(d, u) = q.top();
            vis[u] = true;
            q.pop();
            if(dist[u] < d)    continue;
            for(auto p: adj[u]) {
                int v, w;
                tie(v, w) = p;
                if(vis[v])    continue;
                if(d + w < dist[v]) {
                    dist[v] =  d + w;
                    q.push({d + w, v});
                }
            }
        }
    }
    void solve()
    {
        int a, b;   cin >> a >> b;
        Dijkstra(a);
        cout << dist[b];
    }
};
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    Graph g(n);
    g.solve();
}