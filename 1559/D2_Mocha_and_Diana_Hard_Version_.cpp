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
    set<int> s1, s2;
    vector<int> v1, v2;
    for(int i = 1; i <= n; i++) if(dsu1.find(i) == i)    v1.emplace_back(i);
    for(int i = 1; i <= n; i++) if(dsu2.find(i) == i)    v2.emplace_back(i);

    for(int i )

    cout << ans.size() << '\n';
    for(auto [u, v]: ans)
        cout << u << ' ' << v << '\n';
}