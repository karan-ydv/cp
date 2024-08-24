#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct Graph {
	typedef pair<int, int> item;
	typedef vector<vector<item>> vv;
	vector<int> dist;
	vv adj;
	int n;
	Graph(int v, int e) {
		n = v;
        vector<int> A(n + 1);
        for (int i = 0; i <= n; i++)
            cin >> A[i];

		adj.resize(v + 1);
		dist.resize(v + 1, 1LL << 60);
		while(e--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].emplace_back(v, w + A[u] + A[v]);
			adj[v].emplace_back(u, w + A[u] + A[v]);
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
					dist[v] =  d + w;
					q.push({d + w, v});
				}
			}
		}
	}
	void solve()
	{
		Dijkstra(1);
		for(int i = 1; i <= n; i++)
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