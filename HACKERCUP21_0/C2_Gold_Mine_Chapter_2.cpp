/* compile with 
g++ filename -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> c, par;
    vector<bool> mined;
    set<tuple<int, int, int>> set;
    int V, E;
    int sum, old_ancestor, new_ancestor;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v);
        par.resize(v);
        c.resize(v);
        for(int &x: c)  cin >> x;
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        DFS(0, 0);
    }
    void DFS(int u, int p, int s = 0)
    {
        s += c[u];
        par[u] = p;
        for(auto v: adj[u])
            if(v != p)  DFS(v, u, s);
        
        if(adj[u].size() == 1 and u)
            set.insert({s, u, 0});
    }
    void dfs(int u, int s = 0)
    {
        s += c[u];
        for(auto v: adj[u])
            if(v != par[u]) dfs(v, s);
        if(adj[u].size() == 1 and u)
        {
            for(auto itr = set.begin(); itr != set.end(); itr++)
            if(get<1>(*itr) == u)
            {
                set.erase(itr);
                set.insert({s, u, new_ancestor});
                break;
            }
            // auto itr = set.find({sum + s, u, old_ancestor});
        }
    }
    int solve(int k)
    {
        if(k == 0 or V == 1)  return c[0];
        for(auto [s, u, v]: set)
            cerr << s << ' ' << u << ' ' << v << '\n';
        mined.resize(V);
        int zero_vis = 0, ans = 0;
        while(k--)
        {
            auto itr = set.end();
            auto [sum, u, old_ancestor] = *--itr;
            ans += sum;
            set.erase(itr);
            while(!mined[u])
            {
                mined[u] = 1;
                sum -= c[u];
                new_ancestor = u;
                for(auto v: adj[u])
                    if(v != par[u] and !mined[v]) dfs(v);
                u = par[u];
            }
            if(u == 0)
                zero_vis++;
        }
        cerr << "zero : " << zero_vis << ' ' << ans << '\n';
        if(zero_vis > 1)
        {
            if(set.size())
            {
                auto [s, a, b] = *set.rbegin();
                ans += s;
            }
        }
        else
        {
            int mx = 0;
            for(auto [s, a, b]: set) {
                cerr << s << ' ' << a << ' ' << b << '\n';
                if(b == 0)  mx = max(mx, s);
            }
            ans += mx;
        }
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n, k;  cin >> n >> k;
        Graph g(n, n - 1);
        cout << g.solve(k) << endl;
        cerr << endl;
    }
}