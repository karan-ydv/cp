#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct Graph {
	typedef pair<int, int> item;
	typedef vector<vector<item>> vv;
	vector<int> dist;
    vector<int> A;
	vv adj;
	int n;
	Graph(int v, int e) {
		n = v;
        A.resize(v + 1);
        for (int i = 1; i <= n; i++)
            cin >> A[i];

		adj.resize(v + 1);
		dist.resize(v + 1, 1LL << 60);
		while(e--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		}
	}
	void Dijkstra(int a)
	{
		dist[a] = 0;
		vector<bool> vis(n + 1, false);
		priority_queue<item, vector<item>, greater<item>> q;
		q.push({A[a], a});
        dist[a] = A[a];
		while(!q.empty())
		{
			auto [d, u] = q.top();
			vis[u] = true;
			q.pop();
			if(dist[u] < d)	continue;
			for(auto [v, w]: adj[u]) {
				if(vis[v])	continue;
				if(d + w + A[v] < dist[v]) {
					dist[v] =  d + w + A[v];
					q.push({dist[v], v});
				}
			}
		}
	}
	void solve()
	{
		Dijkstra(1);
		for(int i = 2; i <= n; i++)
			cout << dist[i] << ' ';
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