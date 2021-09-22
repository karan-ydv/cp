#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef pair<int, int> item;
    typedef tuple<int, int, int> ti;
    vector<vector<ti>> adj;
    vector<ti> edges;
    int V, E, sum;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v + 1);
        edges.reserve(e);
        sum = 0;
        for(int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
            sum += w;
            adj[u].emplace_back(w, v, i);
            adj[v].emplace_back(w, u, i);
        }
    }
    void solve()
    {
        int mst = 0;
        vector<bool> used(V + 1, false);

        priority_queue<ti, vector<ti>, greater<ti>> heap;
        for(auto x: adj[1])
            heap.push(x);
        
        used[1] = 1;
        bool treeEdges[E + 1] = {};
        for(int i = 1; i < V; i++)
        {
            int w, u, e;
            while(1)
            {
                tie(w, u, e) = heap.top();
                heap.pop();
                if(!used[u])
                    break;
            }
            used[u] = 1;
            treeEdges[e] = 1;
            mst += w;
            for(auto x: adj[u])
                if(!used[get<1>(x)]) heap.push(x);
        }
        int reward = 0;
        for(int i = 0; i < E; i++) if(!treeEdges[i])
            reward += max(int(0), get<2>(edges[i]));
        cout << reward;
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