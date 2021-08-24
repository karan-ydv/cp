#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5+69;
const int K = 18;

vector<int> adj[N]; // adjacency list
int depth[N];       // depth of Node i

int tin[N], tout[N];
int up[N][K + 1];

int LOG;

bool isAnsector(int u, int v)
{   // return true if u is ancestor of v
    return tin[u] < tin[v] and tout[u] > tout[v];
}

int LCA(int u, int v)
{
    // cerr << u << ' ' << v << " : ";
    if(depth[u] < depth[v]) swap(u, v);
    if(isAnsector(v, u))    return v;
    
    for(int i = LOG; i >= 0; i--)
        if(!isAnsector(up[u][i], v))
            u = up[u][i];
    // cerr << up[u][0] << '\n';
    return up[u][0];
}

void DFS(int u, int p, int h)
{
    static int tiktok = 0;
    tin[u] = ++tiktok;
    depth[u] = h;

    up[u][0] = p;
    for(int i = 1; i <= LOG; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for(auto v: adj[u]) if(v != p)
        DFS(v, u, h + 1);

    tout[u] = ++tiktok;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;   cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v;cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    LOG = ceil(log2(n));
    DFS(1, 1, 0);
    while(q--)
    {
        int u, v;   cin >> u >> v;
        if(u == v)
        {
            cout << "0\n";
            continue;
        }
        int dis = depth[u] + depth[v] - 2 * depth[LCA(u, v)];
        cout << dis << '\n';
    }
}