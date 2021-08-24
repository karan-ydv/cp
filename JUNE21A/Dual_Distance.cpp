#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+69;
const int K = 17;

vector<int> adj[N]; // adjacency list
int sumOfDepth[N];  // sumOfDepths of nodes in subtree of i taking 1 as root
int sumOfDepth2[N]; // sumOfDepths of nodes in subtree of i taking i as root
int sizeOfTree[N];  // size of subtree of node i
int depth[N];       // depth of Node i
int EulerFirst[N];  // index of first occurance of node i in EulerTour
int EulerNode[N];   // id of node at index i in EulerTour

int tin[N], tout[N];
int up[N][K + 1];

int LOG;

bool isAnsector(int u, int v)
{   // return true if u is ancestor of v
    return tin[u] < tin[v] and tout[u] > tout[v];
}
int KthAncestor(int u, int k)
{
    while(k)
    {
        u = up[u][__builtin_ctzll(k)];
        k &= (k - 1);
    }
    return u;
}
int LCA(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    if(isAnsector(v, u))    return v;
    
    for(int i = LOG; i >= 0; i--)
        if(!isAnsector(up[u][i], v))
            u = up[u][i];

    return up[u][0];
}

struct Graph 
{
    int V, E, tiktok;
    Graph(int v, int e) 
    {
        V = v, E = e;
        for(int i = 1; i <= v; i++)
            adj[i].clear();
        for(int i = 0; i < e; i++)
        {
            int u, v;cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    void DFS(int u, int p, int h)
    {
        tin[u] = ++tiktok;
        depth[u] = h;
        sizeOfTree[u] = 1;
        sumOfDepth[u] = 0;

        up[u][0] = p;
        for(int i = 1; i <= LOG; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];

        for(auto v: adj[u]) if(v != p)
        {
            DFS(v, u, h + 1);
            sumOfDepth[u] += sumOfDepth[v] + sizeOfTree[v];
            sizeOfTree[u] += sizeOfTree[v];
        }
        tout[u] = ++tiktok;
    }
    void DFS2(int u, int p)
    {
        sumOfDepth2[u] = sumOfDepth2[p] + sizeOfTree[1] - 2 * sizeOfTree[u];
        for(int v: adj[u])  if(v != p)  DFS2(v, u);
    }
    int query(int u, int v)
    {
        if(depth[u] < depth[v]) swap(u, v);
        int lca = LCA(u, v);
        int dis = depth[u] + depth[v] - 2 * depth[lca];

        if(dis & 1)
        {
            int midChild = KthAncestor(u, dis / 2);
            int mid = up[midChild][0];
            int ans = sumOfDepth2[u] - (sumOfDepth2[mid] - sumOfDepth[midChild] - sizeOfTree[midChild])
                      - (dis / 2 + 1) * (sizeOfTree[1] - sizeOfTree[midChild]);
            ans += sumOfDepth2[v] - sumOfDepth[midChild] - (dis / 2 + 1) * sizeOfTree[midChild];
            return ans;
        }
        int midChild = KthAncestor(u, dis / 2 - 1);
        int mid = up[midChild][0];
        int ans = sumOfDepth2[u] - (sumOfDepth2[mid] - sumOfDepth[midChild] - sizeOfTree[midChild])
                  - (dis / 2) * (sizeOfTree[1] - sizeOfTree[midChild]);
        ans += sumOfDepth2[v] - sumOfDepth[midChild] - (dis / 2 + 1) * sizeOfTree[midChild];
        return ans;
    }
    void solve(int q)
    {
        LOG = ceil(log2(V));
        tiktok = 0;
        DFS(1, 1, 0);
        sumOfDepth2[1] = sumOfDepth[1];
        for(int v: adj[1])  DFS2(v, 1);

        // cerr << "Node:           ";
        // for(int i = 1; i <= V; i++)
        //     cerr << setw(2) << i << ' '; cerr << '\n';
        // cerr << "Depth of Node:  ";
        // for(int i = 1; i <= V; i++)
        //     cerr << setw(2) << depth[i] << ' '; cerr << '\n';
        // cerr << "Size of Tree:   ";
        // for(int i = 1; i <= V; i++)
        //     cerr << setw(2) << sizeOfTree[i] << ' '; cerr << '\n';
        // cerr << "Sum of Depths:  ";
        // for(int i = 1; i <= V; i++)
        //     cerr << setw(2) << sumOfDepth[i] << ' '; cerr << '\n';
        // cerr << "Sum of Depths2: ";
        // for(int i = 1; i <= V; i++)
        //     cerr << setw(2) << sumOfDepth2[i] << ' '; cerr << '\n';
        // cerr << '\n';

        while(q--)
        {   
            int u, v;   cin >> u >> v;
            cout << query(u, v) << '\n';
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, q;	cin >> n >> q;
        Graph g(n, n - 1);
        g.solve(q);
    }
}