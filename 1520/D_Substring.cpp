#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
char S[N];
vector<int> adj[N];
int deg[N];
int dp[N][26];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   scanf("%d %d", &n, &m);
    scanf("%s", S + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        deg[v]--;
    }

    int ans = -1, i = 0;
    queue<int> q;

    for(int i = 1; i <= n; i++) 
    if(deg[i] == 0) q.push(i);

    for(i = 0; i < n and !q.empty(); i++)
    {
        int u = q.front();
        q.pop();
        dp[u][S[u] - 'a'] += 1;
        for(int j = 0; j < 26; j++)
            ans = max(ans, dp[u][j]);
        for(int v: adj[u])
        {
            for(int j = 0; j < 26; j++)
                dp[v][j] = max(dp[u][j], dp[v][j]);
            ++deg[v];
            if(deg[v] == 0)
            q.push(v);
        }
    }
    if(!q.empty() or i < n)
        ans = -1;
    cout << ans;
}