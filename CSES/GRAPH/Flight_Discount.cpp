#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1LL << 60;
struct Graph {
	typedef pair<int, int> item;
	typedef vector<vector<item>> vv;
	vector<array<int, 2>> dist;
	vv adj, adj2;
	int n;
	Graph(int v, int e) {
		n = v;
		adj.resize(v + 1);
		adj2.resize(v + 1);
		dist.resize(v + 1, {INF, INF});
		while(e--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].emplace_back(v, w);
			adj2[v].emplace_back(u, w);
		}
	}
	void Dijkstra(int a)
	{
		int x = a / n;
		dist[a][x] = 0;
		vector<bool> vis(n + 1, false);
		priority_queue<item, vector<item>, greater<item>> q;
		q.push({0, a});
		while(!q.empty())
		{
			auto [d, u] = q.top();
			vis[u] = true;
			q.pop();
			if(dist[u][x] < d)	continue;
			for(auto [v, w]: adj[u]) {
				if(vis[v])	continue;
				if(d + w < dist[v][x]) {
					dist[v][x] =  d + w;
					q.push({d + w, v});
				}
			}
		}
	}
	void solve()
	{
		Dijkstra(1);
		adj.swap(adj2);
		Dijkstra(n);
		adj.swap(adj2);
		int ans = INF;
		for(int u = 1; u < n; u++) {
			for(auto [v, w]: adj[u]) {
				ans = min(ans, dist[u][0] + w / 2 + dist[v][1]);
			}}
		cout << ans;
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