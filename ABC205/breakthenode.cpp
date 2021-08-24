#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 69;
vector<int> adj[N];
int w[N];
pair<int, int> ans;
bitset<N> visited;
int n, m;

priority_queue<int> pq;
int fun(int u)
{
    visited[u] = 1;
    int x = w[u];
    for (int v : adj[u])
        if (!visited[v])
            x += fun(v);
    return x;
}

void DFS(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
        if (!visited[v])
            pq.push(fun(v));
    pair<int, int> p = {0, pq.top()};
    pq.pop();
    p.first = pq.top();
    ans = max(ans, p);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        int sum = 0;
        for (int i = 1; i <= n; i++)
            cin >> w[i], sum += w[i];

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        ans = {0, sum};
        for (int i = 1; i <= n; i++)
        {
            visited.reset();
            pq = priority_queue<int>();
            pq.push(0);
            DFS(i);
        }
        cout << ans.first << ' ' << ans.second << '\n';
    }
}