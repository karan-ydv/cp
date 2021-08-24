#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int modexp(int a, int n){
    int p = 1;
    while(n)
    {
        if(n & 1)	p = p * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return p;
}
struct Graph 
{
    typedef int item;
    vector<vector<item>> child;
    vector<int> dp, par;
    int V, E;
    Graph(int v, int e) 
    {
        V = v, E = e;
        child.resize(v + 1);
        par.resize(V + 1);
        dp.resize(v + 1);
        for(int i = 1; i <= v; i++) {
            cin >> par[i];
            if(i > 1)
            child[par[i]].emplace_back(i);
        }
        // for(int i = 0; i < e; i++)
        // {
        //     int u, v;	cin >> u >> v;
        //     adj[u].emplace_back(v);
        //     adj[v].emplace_back(u);
        // }
    }
    int DFS(int u = 0, int p = -1, int h = 0)
    {
        int c = 0;
        for(auto v: child[u])
        if(v != p)
        {
            c += DFS(v, u, h + 1);
        }
        return c;
    }
    void solve()
    {

    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;   cin >> n >> k;
    Graph(n, n - 1);
    g.solve();
}