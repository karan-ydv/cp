#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Graph {
	typedef pair<int, int> item;
	typedef vector<vector<item>> vv;
	vector<int> a;
	vv adj;
	int n, k;
	Graph(int n, int m, int k) {
		adj.resize(n * m + 1);
		a.resize(n * m + 1);
		this -> n = n * m;
		this -> k = k;

		int node = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++, node++)
				cin >> a[node];
		
		node = 1;
		vector<vector<int>> v = {{0, 1, 2, 3}, {3, 0, 1, 2}, {2, 3, 0, 1}, {1, 2, 3, 0}};
		for(int i = 0; i < n; i++)
		{
			string s;	cin >> s;
			for(int j = 0; j < m; j++, node++)
			{
				int k;
				if(s[j] == 'R')	k = 0;
				if(s[j] == 'D')	k = 1;
				if(s[j] == 'L')	k = 2;
				if(s[j] == 'U')	k = 3;
				adj[node].emplace_back(v[k][0], node + 1);	// R
				adj[node].emplace_back(v[k][1], node + m);	// D
				adj[node].emplace_back(v[k][2], node - 1);	// L
				adj[node].emplace_back(v[k][3], node - m);	// U
			}
		}
	}
	bool possible(int x)
	{
		if(x == 0)	return true;
		// Dijkstra
		vector<int> dist(n + 1, 1LL << 60);
		dist[1] = 0;
		vector<bool> vis(n + 1, false);
		priority_queue<item, vector<item>, greater<item>> q;
		q.push({0, 1});
		while(!q.empty())
		{
			auto [d, u] = q.top();
			vis[u] = true;
			q.pop();
			if(dist[u] < d)	continue;
			for(auto [w, v]: adj[u]) {
				if(v < 1 or v > n)			continue;
				if(vis[v] or a[u] - w < x)	continue;
				if(d + w < dist[v]) {
					dist[v] =  d + w;
					q.push({d + w, v});
				}
			}
		}
		return dist[n] <= k;
	}
	void solve()
	{
		int beg = 0, end = 1e9, ans;
		while(beg <= end)
		{
			int mid = beg + end >> 1;
			if(possible(mid))
				ans = mid, beg = mid + 1;
			else
				end = mid - 1;
		}
		cout << ans << '\n';
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, m, k;	cin >> n >> m >> k;
		Graph g(n, m, k);
		g.solve();
	}
}