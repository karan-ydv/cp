#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr[100000];
vector<bool> vis(100000, 0);
vector<int> res(100000, 0);

int dfs(int node)
{
	vis[node] = 1;
	if (res[node] == 1)
		return 0;

	int min = INT_MAX;
	for (auto child : arr[node])
	{
		if (res[child.first] == 1)
			if (min > child.second)
				min = child.second;
	}
	if (min != INT_MAX)
		return min;

	int c = 0;
	for (auto child : arr[node])
	{
		if (res[child.first] != 1)
		{
			c = c + child.second;
			if (vis[child.first] == 0)
			{
				c = c + dfs(child.first);
				if (min > c)
					min = c;
			}
		}
	}
	vis[node] = 0;
	if (min != INT_MAX)
		return min;
}

int main()
{
	int n, e, u, v, t, r, rn;
	cin >> n >> e;
	for (int i = 1; i <= e; i++)
	{
		cin >> u >> v >> t;
		arr[u].push_back(make_pair(v, t));
		arr[v].push_back(make_pair(u, t));
	}
	cin >> r;
	for (int i = 1; i <= r; i++)
	{
		cin >> rn;
		res[rn] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		int ans = dfs(i);
		cout << ans << endl;
	}
}