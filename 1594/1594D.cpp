#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef pair<int, int> item;
    vector<vector<item>> adj;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        for(int i = 0; i < e; i++)
        {
            int u, v; string s;
            cin >> u >> v >> s;
            if(s == "imposter")
                adj[u].emplace_back(v, 1),
                adj[v].emplace_back(u, 1);
            else
                adj[u].emplace_back(v, 0),
                adj[v].emplace_back(u, 0);
        }
    }
    int BFS()
    {
        int ans = 0;
        queue<int> q;
        vector<int> col(V + 1, -1);
        for(int i = 1; i <= V; i++)
        if(col[i] == -1)
        {
            q.push(i);
            col[i] = 0;
            int cnt[2]{};
            while(!q.empty())
            {
                int f = q.front();
                cnt[col[f]]++;
                q.pop();
                for(auto [v, d]: adj[f])
                {
                    if(col[v] == -1) {
                        col[v] = col[f] ^ d;
                        q.push(v);
                    }
                    else if(col[v] != (col[f] ^ d))
                        return -1;
                }
            }
            ans += max(cnt[0], cnt[1]);
        }
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        Graph g(n, m);
        cout << g.BFS() << '\n';
    }
}