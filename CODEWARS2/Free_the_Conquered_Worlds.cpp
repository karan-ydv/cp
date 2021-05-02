#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 105;
bool adj[N][N];
vector<int> saved(N, -1);
int n, m;

void solve()
{
	int d = 0;
	while(++d)
	{
		vector<int> v;
		for(int i = 0; i < n; i++) 
		if(saved[i] == -1)
		{
			int c = 0;
			for(int x = 0; x < n; x++)	if(adj[i][x])
				c += (saved[x] == -1);
			if(c < 2)
			v.emplace_back(i);
		}
		for(int x: v)
		{
			saved[x] = d;
			for(int i = 0; i < n; i++)
			if(adj[x][i])	adj[x][i] = adj[i][x] = 0;
		}
		if(v.size() == 0)	break;
	}
	for(int i = 0; i < n; i++)
		cout << saved[i] << ' ';
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;	cin >> x >> y;
		adj[x][y] = adj[y][x] = 1;
	}
	solve();
}