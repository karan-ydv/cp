#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> children, depthlist;
    vector<int> in, out, depth;
    int V, E, timer;
    Graph(int v) 
    {
        V = v, E = v - 1;
        children.resize(v + 1);
        depthlist.resize(v + 1);
        depth.resize(v + 1);
        in.resize(v + 1);
        out.resize(v + 1);
        for(int i = 2; i <= v; i++)
        {
            int p;  cin >> p;
            children[p].emplace_back(i);
        }
    }
    void DFS(int u)
    {
        in[u] = timer++;
        depthlist[depth[u]].emplace_back(in[u]);
        for(int v: children[u])
        {
            depth[v] = depth[u] + 1;
            DFS(v);
        }
        out[u] = timer++;
    }
    int query(int u, int d)
    {
        vector<int> &v = depthlist[d];
        return lower_bound(v.begin(), v.end(), out[u]) - lower_bound(v.begin(), v.end(), in[u]);
    }
    void solve(int q)
    {
        timer = 0;
        DFS(1);
        while(q--)
        {
            int u, d;   cin >> u >> d;
            if(d <= depth[u])   cout << (d == depth[u]);
            else                cout << query(u, d);
            cout << '\n';
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    Graph g(n);
    int q;  cin >> q;
    g.solve(q);
}