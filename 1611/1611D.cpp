#include <bits/stdc++.h>
#define int int64_t
#define f first
#define s second
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> par, p, ans;
    int V, E, root;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        par.resize(v + 1);
        ans.resize(v + 1);
        p.resize(v + 1);
        for(int i = 1; i <= v; i++)
        {
            cin >> par[i];
            if(par[i] == i)
                root = i;
            else
                adj[par[i]].emplace_back(i);
        }
        // for(int i = 1; i <= v; i++) {
        //     clog << i << " : ";
        //     for(int u: adj[i])  clog << u << ' ';
        //     clog << '\n';
        // }
        for(int i = 1; i <= v; i++) {
            int x;  cin >> x;
            p[x] = i;
        }
    }
    void solve()
    {

        typedef tuple<int, int, int> pii;
        priority_queue<pii, deque<pii>, greater<>> q;
        q.push({p[root], 0, root});
        int pre = -1, idx = 1;
        while(!q.empty())
        {
            auto [i, d, x] = q.top();
            q.pop();
            // clog << i << ' ' << d << ' ' << x << '\n';
            if(i != idx)
                return cout << "-1\n", void();
            if(d <= pre)
            {
                ans[x] = pre - d + 1;
                d = pre + 1;
            }
            for(int u: adj[x])
                q.push({p[u], d, u});
            pre = d;
            idx++;
        }
        // clog << '\n';
        for(int i = 1; i <= V; i++)
            cout << ans[i] << " \n"[i == V];
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        Graph g(n, n - 1);
        g.solve();
    }
}