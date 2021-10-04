#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
// const int N = 2e5 + 69;
const int N = 10;
int dp[N], d[N];
bool visited[N];

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        adj.resize(v + 1);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    int BFS()
    {
        queue<int> q;
        dp[1] = 1;
        d[1] = 0;
        q.push(1);
        visited[1] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v: adj[u])
            {
                if(!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                    dp[v] = dp[u];
                    d[v] = d[u] + 1;
                }
                else
                {
                    if(d[v] == d[u] + 1)
                        (dp[v] += dp[u]) %= mod;
                }
            }
        }
        return dp[V];
    }
    void solve()
    {
        cout << BFS();
        // for(int i = 1; i <= V; i++)
        //     cerr << dp[i] << " \n"[i == V];
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