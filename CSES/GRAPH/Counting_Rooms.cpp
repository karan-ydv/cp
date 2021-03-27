#include <bits/stdc++.h>
using namespace std;

struct GridGraph {
	vector<string> grid;
	vector<vector<bool>> visited;
	vector<pair<int, int>> D = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int n, m;
	GridGraph(int n, int m) {
		this -> n = n;
		this -> m = m;
		grid.resize(n);
		visited.resize(n, vector<bool>(m));
		for(int i = 0; i < n; i++)
			cin >> grid[i];
	}
	bool BFS(int a, int b)
	{
		queue<tuple<int, int, int>> q;
		q.push({a, b, 0});
		while(!q.empty())
		{
			auto [x, y, d] = q.front();
			q.pop();
			visited[x][y] = 1;
			for(auto [dx, dy]: D)
			{
				if(x + dx < 0 or x + dx >= n)	continue;
				if(y + dy < 0 or y + dy >= m)	continue;
				int xx = x + dx, yy = y + dy;
				if(grid[xx][yy] == '.' and !visited[xx][yy]) {
					visited[xx][yy] = 1;
					q.push({xx, yy, d + 1});
				}
			}
		}
		return true;
	}
	int rooms() {
		int c = 0;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		if(grid[i][j] == '.' and !visited[i][j])
			c += BFS(i, j);
		return c;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	GridGraph g(n, m);
	cout << g.rooms();
}