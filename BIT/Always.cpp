#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tiii;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int a[n][m], d[n][m];

	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	cin >> a[i][j], d[i][j] = 1 << 30;

	d[0][0] = 0;
	pair<int, int> delta[] = {
		{0, -1}, {0, 1}, {1, 0}, {-1, 0}
	};
	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
	pq.push({0, 0, 0});
	while(!pq.empty())
	{
		auto [c, x, y] = pq.top();
		pq.pop();
		for(auto [dx, dy]: delta) {
			int i = x + dx;
			int j = y + dy;
			if(i < 0 or i >= n or j < 0 or j >= m)
				continue;
			if(max(c, a[i][j]) < d[i][j]) {
				d[i][j] = max(c, a[i][j]);
				pq.push({d[i][j], i, j});
			}
		}
	}
	cout << d[n - 1][m - 1];
}