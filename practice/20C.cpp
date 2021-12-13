#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1LL << 60;

struct Graph {
	typedef pair<int, int> item;
	typedef vector<vector<item>> vv;
	vector<int> dist, prev;
	vv adj;
	int n;
	Graph(int v, int e) : n(v) {
		adj.resize(v + 1);
		dist.resize(v + 1, inf);
        prev.resize(v + 1, -1);
		while(e--)
		{
			int u, v, w; cin >> u >> v >> w;
            adj[v].emplace_back(u, w);
			adj[u].emplace_back(v, w);
		}
	}
	void Dijkstra(int a)
	{
		dist[a] = 0;
		vector<bool> vis(n + 1, false);
		priority_queue<item, vector<item>, greater<item>> q;
		q.push({0, a});
		while(!q.empty())
		{
			auto [d, u] = q.top();
			vis[u] = true;
			q.pop();
			if(dist[u] < d)	continue;
			for(auto [v, w]: adj[u]) {
				if(vis[v])	continue;
				if(d + w < dist[v]) {
                    prev[v] = u;
					dist[v] =  d + w;
					q.push({d + w, v});
				}
			}
		}
	}
	void solve()
	{
		Dijkstra(1);
        if(dist[n] == inf)
            cout << "-1";
        else
        {
            stack<int> stack;
            while(n != -1)
            {
                stack.push(n);
                n = prev[n];
            }
            while(!stack.empty())
            {
                cout << stack.top() << ' ';
                stack.pop();
            }
        }
	}
};
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	Graph g(n, m);
	g.solve();
}