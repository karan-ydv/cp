#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct DSU{
    vector<int> parent, weight;
    DSU(int n) {
        parent.resize(n + 1);
        weight.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if(parent[x] == x)    return x;
        return parent[x] = find(parent[x]);
    }
    void UNION(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(weight[x] > weight[y]) swap(x, y);
        if(x != y)
        {
            parent[x] = y;
            weight[y] += weight[x];
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU dsu1(n), dsu2(n);
    
    for(int i = 1; i <= m1; i++)
    {
        int u, v;   cin >> u >> v;
        dsu1.UNION(u, v);
    }
    for(int i = 1; i <= m2; i++)
    {
        int u, v;   cin >> u >> v;
        dsu2.UNION(u, v);
    }
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
    {
        bool f1 = (dsu1.find(i) == dsu1.find(j));
        bool f2 = (dsu2.find(i) == dsu2.find(j));
        if(f1 or f2)   continue;
        dsu1.UNION(i, j);
        dsu2.UNION(i, j);
        ans.emplace_back(i, j);
    }
    cout << ans.size() << '\n';
    for(auto [u, v]: ans)
        cout << u << ' ' << v << '\n';
}