/* compile with 
g++ C1_Gold_Mine_Chapter_1.cpp -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> c;
    vector<bool> vis;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v);
        c.resize(v);
        for(int &x: c)  cin >> x;
        for(int i = 0; i < e; i++)
        {
            int u, v;	cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    int DFS(int u)
    {
        vis[u] = 1;
        int mx = 0;
        for(auto v: adj[u]) if(!vis[v])
            mx = max(mx, DFS(v));
        return c[u] + mx;
    }
    int solve()
    {
        vis.resize(V);
        priority_queue<int> heap;
        vis[0] = 1;
        for(int u: adj[0])
        {
            heap.push(-DFS(u));
            if(heap.size() > 2)
               heap.pop();
        }
        int ans = c[0];
        while(!heap.empty())
        {
            ans -= heap.top();
            heap.pop();
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
        int n;  cin >> n;
        Graph g(n, n - 1);
        cout << g.solve() << '\n';
    }
}