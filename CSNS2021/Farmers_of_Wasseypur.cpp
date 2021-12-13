#include <bits/stdc++.h>
using namespace std;

#define ld long double
const int mod = 1e9 + 7;

struct Graph
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> type;
    int V, E, a, b;
    long double ans;
    Graph(int v, int e) : V(v), E(e)
    {
        adj.resize(v + 1);
        type.resize(v + 1);
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for (int i = 1; i <= v; i++)
            cin >> type[i];
        ans = -INFINITY;
    }
    typedef pair<ld, int> pdi;
    pair<pdi, pdi> DFS(int u, int p)
    {

        priority_queue<pdi> maxHeap;
        priority_queue<pdi, deque<pdi>, greater<pdi>> minHeap;

        for (int v : adj[u])
            if (v != p)
            {
                auto x = DFS(v, u);
                minHeap.push(x.first);
                maxHeap.push(x.second);
                if (minHeap.size() > 2)
                {
                    minHeap.pop();
                    maxHeap.pop();
                }
                maxHeap.push(x.first);
                minHeap.push(x.second);
                if (minHeap.size() > 2)
                {
                    minHeap.pop();
                    maxHeap.pop();
                }
            }
        vector<pdi> v;
        while (!minHeap.empty())
        {
            v.push_back(minHeap.top());
            minHeap.pop();
        }

        while (!maxHeap.empty())
        {
            v.push_back(maxHeap.top());
            maxHeap.pop();
        }

        pdi mn = {type[u], u}, mx = mn;
        for (auto [x, y] : v)
        {
            mn = min(mn, {type[u] * x, y});
            mx = max(mx, {type[u] * x, y});
        }

        if (mx.first > ans)
        {
            ans = mx.first;
            a = mx.second;
            b = u;
        }

        int n = (int)v.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                ld z = v[i].first * v[j].first * type[u];
                if (z > ans)
                {
                    ans = z;
                    a = v[i].second;
                    b = v[j].second;
                }
            }
        // clog << u << " : (" << mx.first << ' ' << mx.second << ") (" << mn.first << ' ' << mn.second << ")\n";
        return {mx, mn};
    }
    int BFS()
    {
        queue<pair<item, int>> q;
        unordered_set<item> visited;
        q.push({a, (type[a] + mod) % mod});
        while (!q.empty())
        {
            auto [u, d] = q.front();
            // clog << u << ' ' << d << '\n';
            q.pop();
            visited.insert(u);
            for (auto v : adj[u])
            {
                int z = (d * type[v] % mod + mod) % mod;
                if (v == b)
                    return z;
                if (!visited.count(v))
                {
                    q.push({v, z});
                }
            }
        }
        return -1;
    }
    int solve()
    {
        DFS(1, -1);
        // clog << a << ' ' << b << '\n';
        if (a == b)
            return (type[a] + mod) % mod;
        return BFS();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Graph g(n, n - 1);
        cout << g.solve() << '\n';
    }
}