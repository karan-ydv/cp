#include <bits/stdc++.h>
using namespace std;

struct GridGraph {
	vector<string> grid;
	vector<tuple<int, int, char>> D = {{1, 0, 'D'}, {-1, 0, 'U'}, {0, 1, 'R'}, {0, -1, 'L'}};
	vector<bool> visited;
	vector<int> parent;
	vector<char> direction;
	int n, m;
	GridGraph(int n, int m) {
		this -> n = n;
		this -> m = m;
		grid.resize(n);
		visited.resize(m * n);
		parent.resize(m * n, -1);
		direction.resize(m * n);
		for(int i = 0; i < n; i++)
			cin >> grid[i];
	}
	int BFS(int a, int b)
	{
		queue<tuple<int, int>> q;
		q.push({a, b});
		visited[a * m + b] = 1;
		while(!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for(auto [dx, dy, c]: D)
			{
				int xx = x + dx, yy = y + dy;
				if(xx < 0 or xx >= n)		continue;
				if(yy < 0 or yy >= m)		continue;
				if(visited[xx * m + yy])	continue;
				if(grid[xx][yy] == '#')		continue;

				parent[xx * m + yy] = x * m + y;
				direction[xx * m + yy] = c;

				if(grid[xx][yy] == 'B')	return xx * m + yy;
				visited[xx * m + yy] = 1;
				q.push({xx, yy});
			}
		}
		return -1;
	}
	void labyrinth() {
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		if(grid[i][j] == 'A')
		{
			int x = BFS(i, j);
			if(x == -1)
				return cout << "NO", void();
			string path = "";
			while(parent[x] != -1) {
				path += direction[x];
				x = parent[x];
			}
			reverse(path.begin(), path.end());
			cout << "YES\n" << path.length() << '\n' << path;
			return;
		}
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	GridGraph g(n, m);
	g.labyrinth();
}