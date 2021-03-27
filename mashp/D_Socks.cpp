#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU{
	vector<int> parent, weight;
	DSU(int n) {
		parent.resize(n + 1);
		weight.resize(n + 1, 1);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int x)
	{
		if(parent[x] == x)    return x;
		return parent[x] = find(parent[x]);
	}
	void UNION(int x, int y)
	{
		x = find(x);
		y = find(y);
		if(weight[x] > weight[y]) swap(x, y);
		if(x != y)
		{
			parent[x] = y;
			weight[y] += weight[x];
		}
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;	cin >> n >> m >> k;
	DSU dsu(n);
	int color[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> color[i];
	for(int i = 0; i < m; i++) {
		int l, r;	cin >> l >> r;
		dsu.UNION(r, l);
	}
	map<int, vector<int>> mp;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int p = dsu.find(i);
		mp[p].emplace_back(i);
	}
	for(auto [x, v]: mp) {
		map<int, int> f;
		for(int y: v) {
			f[color[y]]++;
		}
		int s = v.size(), t = 1e7;
		for(auto [a, b]: f) {
			t = min(t, s - b);
		}
		ans += t;
	}
	cout << ans;
}