#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 3e5+5;
list<pair<int, int>> adj[N];
bool visited[N];
int asphalt[N];
stack<int> later;

int x;

void dfs(int u, int p, int e)
{
    visited[u] = 1;
    for(auto [v, ei]: adj[u])
    if(!visited[v]) dfs(v, u, ei);
    
    if(p)
    {
        if(asphalt[u] + asphalt[p] < x)
            later.push(e);
        else
        {
            asphalt[p] += asphalt[u] - x;
            asphalt[u] = 0;
            cout << e << '\n';
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, sum = 0;
    cin >> n >> m >> x;

    for(int i = 1; i <= n; i++)
        cin >> asphalt[i], sum += asphalt[i];
    
    if(sum < (n - 1) * x)
        return cout << "NO\n", 0;
    
    for(int i = 1; i <= m; i++)
    {
        int u, v;   cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    cout << "YES\n";
    dfs(1, 0, 0);
    while(!later.empty())
    {
        cout << later.top() << '\n';
        later.pop();
    }
}