#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool palindrome(map<int, int> &mp) {
    int c = 0, d = 0;
    for(auto [x, f]: mp)
        c += f & 1, d += f;
    return (c < 2 and d > 0);
}

struct Graph 
{
    typedef pair<int, int> item;
    vector<vector<item>> adj;
    int V;
    Graph(int v) : V(v) {
        adj.resize(v + 1);
    }
    int DFS(int u, int p, map<int, int> mp) {
        int c = palindrome(mp);
        for(auto [v, x]: adj[u]) if(v != p) {
            mp[x]++;
            c += DFS(v, u, mp);
            mp[x]--;
        }
        return c;
    }
};

int numNicePairs(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight)
{
    Graph g(g_nodes);
    for(int i = 0; i + 1 < g_nodes; i++) {
        g.adj[g_from[i]].emplace_back(g_to[i], g_weight[i]);
        g.adj[g_to[i]].emplace_back(g_from[i], g_weight[i]);
    }
    int ans = 0;
    for(int i = 1; i <= g_nodes; i++) {
        map<int, int> mp;
        int x = g.DFS(i, -1, mp);
        ans += x;
    }
    return ans / 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;  cin >> n >> m;
    vector<int> f, t, w;
    for(int i = 0; i < m; i++) {
        int a, b, c;    cin >> a >> b >> c;
        f.emplace_back(a);
        t.emplace_back(b);
        w.emplace_back(c);
    }
    cout << numNicePairs(n, f, t, w);
}