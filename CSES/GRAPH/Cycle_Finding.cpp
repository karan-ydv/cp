#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e15;
struct Graph {
	typedef tuple<int, int, int> item;
	typedef vector<item> vv;
	vv edges;
	int n;
	Graph(int V, int E) {
		n = V;
		edges.resize(E);
		for(int i = 0; i < E; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			edges[i] = {u, v, w};
		}
	}
	void BellmanFord()
	{
		vector<int> dist(n, INF);
		vector<int> p(n, -1);
		dist[0] = 0;
		int x;
		for(int i = 0; i < n; i++) {
			x = -1;
			for(auto [u, v, w]: edges) {
				if(dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					p[v] = u;
					x = v;
				}
			}
		}
		if(x == -1)
			return cout << "NO", void();
		
		for(int i = 0; i < n; i++)
			x = p[x];
        
		vector<int> cycle;
		for(int v = x;; v = p[v]) {
			cycle.push_back(v + 1);
			if(v == x and cycle.size() > 1)
				break;
		}
		reverse(cycle.begin(), cycle.end());
		cout << "YES\n";
		for(int u: cycle)	cout << u << ' ';
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	Graph g(n, m);
	g.BellmanFord();
}