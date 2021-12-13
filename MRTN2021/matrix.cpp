#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    vector<vector<int>> adj;
    int V, E;
    Graph(int v) : V(v)
    {
        adj.resize(v);
    }
    int BFS(int x, int y)
    {
        queue<pair<int, int>> q;
        vector<bool> visited(V);
        q.push({x, 0});
        while(!q.empty())
        {
            auto [u, d] = q.front();
            q.pop();
            if(u == y)  return d;
            visited[u] = 1;
            for(auto v: adj[u])
            if(!visited[v]) {
                q.push({v, d + 1});
            }
        }
        return -1;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    int A[n][m];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin >> A[i][j];

    Graph g(n * m);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    {
        for(int a = 0; a < n; a++)
        for(int b = 0; b < m; b++)
        {
            if(a == i and b == j)   continue;
            if(abs(i - a) + abs(j - b) == 1 or A[i][j] % A[a][b] == 0)
                g.adj[i * m + j].emplace_back(a * m + b);
        }
    }

    int q;  cin >> q;
    while(q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if(g.BFS(x1 * m + y1, x2 * m + y2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}