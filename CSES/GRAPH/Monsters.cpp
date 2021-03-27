#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, char>> D = {{1, 0, 'D'}, {-1, 0, 'U'}, {0, 1, 'R'}, {0, -1, 'L'}};
struct GridGraph {
	vector<string> grid;
	vector<vector<bool>> visited;
	vector<vector<int>> dist;
	vector<char> direction;
	vector<int> parent;
	int n, m;

	GridGraph(int n, int m) {
		this -> n = n;
		this -> m = m;
		grid.resize(n);
		parent.resize(n * m, -1);
		direction.resize(n * m);
		visited.resize(n, vector<bool>(m, false));
		dist.resize(n, vector<int>(m, 1 << 30));
		for(int i = 0; i < n; i++)
			cin >> grid[i];
	}

	int BFS(int a, int b)
	{
		queue<tuple<int, int, int>> q;
		q.push({a, b, 0});
		visited[a][b] = 1;
		while(!q.empty())
		{
			auto [x, y, d] = q.front();
			q.pop();
			if(x == 0 or x == n - 1)
				return x * m + y;
			if(y == 0 or y == m - 1)
				return x * m + y;
			for(auto [dx, dy, c]: D)
			{
				int xx = x + dx, yy = y + dy;
				if(xx < 0 or xx >= n)		continue;
				if(yy < 0 or yy >= m)		continue;
				if(grid[xx][yy] == '#')		continue;
				if(visited[xx][yy])			continue;
				if(dist[xx][yy] <= d + 1)	continue;

				direction[xx * m + yy] = c;
				parent[xx * m + yy] = x * m + y;
				visited[xx][yy] = 1;
				q.push({xx, yy, d + 1});
			}
		}
		return -1;
	}

	void solve() {
		int a, b;
		queue<tuple<int, int>> q;

		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		if(grid[i][j] == 'M')
		{
			dist[i][j] = 0;
			q.push({i, j});
		}
		else if(grid[i][j] == 'A')
			a = i, b = j;
		
		while(!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for(auto [dx, dy, c]: D) {
				int xx = x + dx, yy = y + dy;
				if(xx < 0 or xx >= n)	continue;
				if(yy < 0 or yy >= m)	continue;
				if(grid[xx][yy] != '#' and dist[xx][yy] == 1 << 30) {
					dist[xx][yy] = dist[x][y] + 1;
					q.push({xx, yy});
				}
			}
		}

		int v = BFS(a, b);
		if(v == -1)	return cout << "NO", void();

		string path = "";
		while(parent[v] != -1) {
			path += direction[v];
			v = parent[v];
		}

		reverse(path.begin(), path.end());
		cout << "YES\n" << path.length() << '\n' << path;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	GridGraph g(n, m);
	g.solve();
}