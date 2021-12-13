#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[N], prv[N];
// dp[sum] = no. of copies of of v required to get sum

int knapsack(vector<int> &V, int X)
{
    unordered_map<int, int> mp;
    for(int x: V) if(x) mp[x]++;

    for(int i = 1; i <= X; i++)
        dp[i] = prv[i] = -1;

    for(auto [v, f]: mp)
    for(int i = 0;  i + v <= X; i++)
    if(dp[i] != -1 and dp[i + v] == -1)
    {
        if(prv[i] != v)
            dp[i + v] = 1;
        else if(dp[i] < f)
            dp[i + v] = 1 + dp[i];
         prv[i + v] = v;
    }

    for(int i = X; i > 0; i--)
        if(dp[i] != -1) return i;
    return 0;
}

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> items;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u, int p, bool h)
    {
        if(h) items.emplace_back(abs((int)adj[u].size() - 1 - (u != 1)));
        for(auto v: adj[u]) if(v != p) DFS(v, u, !h);
    }
    int solve(int q)
    {
        DFS(1, -1, true);
        int sum = accumulate(items.begin(), items.end(), 0);
        if(q == 1)  return sum;
        return sum - 2 * knapsack(items, sum / 2);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, q;   cin >> n >> q;
        Graph g(n, n - 1);
        cout << g.solve(q) << '\n';
    }
}