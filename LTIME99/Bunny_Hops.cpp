#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
struct Graph
{
    typedef int item;
    vector<vector<item>> child;
    vector<int> par, rating, dp;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        child.resize(v);
        par.resize(v);
        rating.resize(v);
        dp.resize(v);
        for(int i = 1; i <= e; i++)
        {
            int p;  cin >> p;
            par[i] = --p;
            child[p].emplace_back(i);
        }
        for(int &x: rating) cin >> x;
        DFS(0);
        dfs(0);
    }
    int DFS(int u)
    {
        for(int c: child[u])
        {
            if(rating[c] < rating[u])
                (dp[u] += DFS(c)) %= mod;
            else
                DFS(c);
        }
        if(child[u].empty())
            return 1;
        return dp[u];
    }
    void dfs(int u)
    {
        for(int c: child[u])
        {
            if(rating[c] > rating[u])
                (dp[c] += dp[u] + 1) %= mod;
            dfs(c);
        }
    }
    void solve()
    {
        int ans = 0;
        for(int i = 0; i < V; i++)
            (ans += dp[i]) %= mod;
        for(int x: dp)  cerr << x << ' '; cerr << '\n';
        cout << ans << '\n';
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
        Graph g(n, n - 1);
        g.solve();
    }
}