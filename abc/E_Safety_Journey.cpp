#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 5005;
vector<int> adj[N];
int dp[N], pd[N];

inline void add(int &x, int v) {
    x += v; if(x >= mod) x -= mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++)
        adj[i].emplace_back(i);
    
    for(int i = 0; i < m; i++)
    {
        int u, v;cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dp[1] = 1;
    for(int i, j = 1, s = 1, t; j <= k; j++, swap(dp, pd), s = t)
        for(i = 1, t = 0; i <= n and (pd[i] = s); add(t, pd[i++]))
            for(int x: adj[i]) add(pd[i], mod - dp[x]);

    cout << dp[1];
}