#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    vector<vector<int>> adj;
    vector<int> status;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v);
    }
    int BFS()
    {
        queue<pair<int, int>> q;
        int n = status.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(status[i] == 3) {
                q.push({i, 0});
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            auto [u, d] = q.front();
            q.pop();
            visited[u] = true;
            for(auto v: adj[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    if(status[v] == 1)
                        ans = max(ans, d + 1);
                    q.push({v, d + 1});
                }
            }
        }
        return ans;
    }
};

int findMinimumTime(int centre_nodes, vector<int> centre_from, vector<int> centre_to, vector<int> status)
{
    Graph g(centre_nodes, centre_from.size());
    for(int i = 0; i < (int) centre_from.size(); i++) {
        g.adj[centre_from[i] - 1].push_back(centre_to[i] - 1);
        g.adj[centre_to[i] - 1].push_back(centre_from[i] - 1);
    }
    g.status = status;
    return g.BFS();
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << findMinimumTime(6, vector<int>{1, 2, 3, 4, 5, 6}, vector<int>{2, 3, 4, 5, 6, 1}, vector<int>{3, 2, 1, 2, 1, 2});
}