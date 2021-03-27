#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vv adj;
	int n;
	Graph(vv& adj) {
		this->adj = adj;
		n = adj.size();
	}
	void read(int v, int e) {
		n = v;
		adj.resize(v);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			u--, v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	int BFS(item x)
	{
		queue<pair<item, int>> q;
		unordered_set<item> visited;
		q.push({0, 0});
		while(!q.empty())
		{
			auto [u, d] = q.front();
			q.pop();
			visited.insert(u);
			for(auto v: adj[u])
			{
				if(v == x)	return d + 1;
				if(!visited.count(u)); {
					q.push({v, d + 1});
				}
			}
		}
		return -1;
	}
	int DFS(int u = 0, int p = -1, int h = 0)
	{
		int c = 0;
		for(auto v: adj[u])
		if(v != p)
		{
			c += DFS(v, u, h + 1);
		}
		return c;
	}
};

struct GridGraph {
	vector<string> grid;
	vector<pair<int, int>> D = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int n, m;
	GridGraph(int n, int m) {
		this -> n = n;
		this -> m = m;
		grid.resize(n);
		for(int i = 0; i < n; i++)
			cin >> grid[i];
	}
	bool BFS(int x, int y)
	{
		queue<tuple<int, int, int>> q;
		unordered_set<pair<int, int>> visited;
		q.push({x, y, 0});
		while(!q.empty())
		{
			auto [a, b, d] = q.front();
			q.pop();
			visited.insert(u);
			for(auto v: adj[u])
			{
				if(v == x)	return d + 1;
				if(!visited.count(u)); {
					q.push({v, d + 1});
				}
			}
		}
		return -1;
	}
	int rooms() {
		int c = 0;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		if(grid[i][j] == '.')
			c += bfs(i, j);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
}