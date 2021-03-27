#include <bits/stdc++.h>
using namespace std;

int n, m, k;	
string grid[1000];
int MAX[1000][1000];

vector<pair<int, int>> D = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(int r, int c, int d)
{
	bool vis[n][m] = {0};
	vis[r][c] = 1;
	queue<tuple<int, int, int>> q;
	q.push({r, c, d});
	while(!q.empty())
	{
		auto [x, y, z] = q.front();
		vis[x][y] = true;
		grid[x][y] = '?';
		q.pop();
		if(MAX[x][y] < z)
		{
			MAX[x][y] = z;
			for(auto [dx, dy]: D)
			{
				int a = x + dx, b = y + dy;
				if(grid[a][b] != '#') {
					if(z > 0 and !vis[a][b])
					{
						q.push({a, b, z - 1});
						vis[a][b] = 1;
					}
				}
			}
		}
	}
}

int sx = -1, sy = -1;
int ex = -1, ey = -1;

int bfs2()
{
	bool vis[n][m] = {0};
	vis[sx][sy] = 1;
	queue<tuple<int, int, int>> q;
	q.push({sx, sy, 0});
	while(!q.empty())
	{
		auto [x, y, z] = q.front();
		vis[x][y] = 1;
		q.pop();
		for(auto [dx, dy]: D)
		{
			int a = x + dx, b = y + dy;
			if(grid[a][b] != '#' and grid[a][b] != '?') {
				if(a == ex and b == ey)
					return z + 1;
				if(!vis[a][b])
				{
					q.push({a, b, z + 1});
					vis[1][1] = 1;
				}
			}
		}
	}
	return -1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> grid[i];

	while(k--)
	{
		int r, c, d;	cin >> r >> c >> d;
		bfs(r - 1, c - 1, d);
	}
	// for(auto x: grid)	cout << x << '\n';

	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	{
		if(grid[i][j] == 'S')	sx = i, sy = j;
		if(grid[i][j] == 'E')	ex = i, ey = j;
	}

	if(sx == -1 or ex == -1) {
		cout << "IMPOSSIBLE";
	}
	else
	{
		int ans = bfs2();
		if(ans == -1)	cout << "IMPOSSIBLE";
		else			cout << ans;
	}
}