#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define N 200005

vector<int> adj[N];
int dp[N], parent[N];

void DFS(int n, int p)
{
    parent[n] = p;
    for(int v: adj[n]) if(v != p)
        DFS(v, n);
}

void DFS(int u)
{
    dp[u] = 1;
    for(int v: adj[u]) if(v != parent[u])
    {
        DFS(v);
        dp[u] = ((long long)dp[u] * (1 + dp[v])) % mod;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, blacknode;
    cin >> n >> blacknode;
    for(int i = 1; i < n; i++)
    {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 1);
    DFS(blacknode);
    cout << dp[blacknode];
}