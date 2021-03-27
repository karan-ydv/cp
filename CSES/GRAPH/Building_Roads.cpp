#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vector<int> visited;  
	vv adj;
	int n;
	Graph(vv& adj) {
		this->adj = adj;
		n = adj.size();
		visited.resize(n + 1);
	}
	Graph(int v, int e) {
		n = v;
		adj.resize(v + 1);
		visited.resize(n + 1);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	void DFS(int u)
	{
		visited[u] = 1;
		for(auto v: adj[u])
		if(!visited[v])	DFS(v);
	}
	void solve() {
		vector<int> v;
		for(int i = 1; i <= n; i++) {
			if(!visited[i]) {
				v.emplace_back(i);
				DFS(i);
			}
		}
		cout << v.size() - 1 << '\n';
		for(int i = 1; i < v.size(); i++) {
			cout << v[0] << ' ' << v[i] << '\n';
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