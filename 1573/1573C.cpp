#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> vis, dp; int V, E;
    Graph(int v) : V(v)
    {
        adj.resize(v + 1);
        vis.resize(v + 1);
        dp.resize(v + 1);
        for(int i = 1; i <= v; i++)
        {
            int k;  cin >> k;
            adj[i].resize(k);
            for(int &x: adj[i])
                cin >> x;
        }
    }
    bool DFS(int u)
    {
        if(vis[u])  return vis[u] == 2;
        vis[u] = 1;
        dp[u] = 1;
        for(auto v: adj[u])
        {
            if(vis[v] == 1) return false;
            if(DFS(v) == false) return false;
            dp[u] = max(dp[u], dp[v] + int(v > u));
        }
        vis[u] = 2;
        return true;
    }
    int solve()
    {
        int ans = 1;
        for(int i = 1; i <= V; i++)
        if(vis[i] == 0)
        {
            if(DFS(i) == false)
                return -1;
            ans = max(ans, dp[i]);
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
        int n;	cin >> n;
        Graph g(n);
        cout << g.solve() << '\n';
    }
}