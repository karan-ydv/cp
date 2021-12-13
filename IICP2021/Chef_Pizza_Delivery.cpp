#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Graph 
{
    vector<int> degree;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        degree.resize(v + 1);
        for(int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }
    }
    bool solve(int k)
    {
        vector<int> v;
        for(int i = 1; i <= V and v.size() < 3; i++)
            if(degree[i] & 1)   v.emplace_back(i);
        
        if(v.size() == 0)   return true;
        if(v.size() == 2 and (v[0] == k or v[1] == k))
            return true;
        return false;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        Graph g(n, m);
        g.solve(k) ? cout << "YES\n" : cout << "NO\n";
    }
}