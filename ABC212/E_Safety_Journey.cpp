#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 5005;
int adj[N][N], dp[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(adj, N * N, 1);
    int n, m, k;    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        adj[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v;   cin >> u >> v;
        adj[u][v] = adj[v][u] = 0;
    }
    
}