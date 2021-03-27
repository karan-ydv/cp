#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vector<int> team;
	vv adj;
	int n;
	Graph(int v, int e) {
		n = v;
		adj.resize(v + 1);
		team.resize(n + 1, -1);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	bool BFS(int beg)
	{
		queue<int> q;
		q.push(beg);
		team[beg] = 1;
		while(!q.empty())
		{
			auto u = q.front();
			q.pop();
			for(auto v: adj[u])
			{
				if(team[v] == -1) team[v] = team[u] ^ 3, q.push(v);
				else if(team[v] == team[u])		return false;
			}
		}
		return true;
	}
	void solve() {
		for(int i = 1; i <= n; i++) {
			if(team[i] == -1) {
				if(!BFS(i))
					return cout << "IMPOSSIBLE", void();
			}
		}
		for(int i = 1; i <= n; i++)	cout << team[i] << ' ';
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