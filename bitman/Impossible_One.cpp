#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> parent, weight, rating;
	DSU(int n) {
		parent.resize(n + 1);
		weight.resize(n + 1, 1);
		rating.resize(n + 1);
		iota(parent.begin(), parent.end(), 0);
		iota(rating.begin(), rating.end(), 0);
	}
	int find(int x)
	{
		if(parent[x]==x)    return x;
		return parent[x]=find(parent[x]);
	}
	void UNION(int x,int y)
	{
		x = find(x);
		y = find(y);
		if(weight[x] > weight[y]) swap(x,y);
		if(x != y)
		{
			parent[x] = y;
			weight[y] += weight[x];
			rating[y] ^= rating[x];
		}
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, e;	cin >> n >> e;
		DSU d(n);
		while(e--) {
			int u, v;	cin >> u >> v;
			d.UNION(u, v);
		}
		int mx = 0, num;
		vector<int> v;
		for(int i = 1; i <= n; i++) { 
			if(d.find(i) == i) {
				// cout << d.rating[i] << ' ';
				v.emplace_back(d.rating[i]);
				if(d.rating[i] > mx) {
					mx = d.rating[i];
					num = i;
				}
			}
		}
		// int ans = -1;
		// for(int i = 1; i <= n; i++)
		// if(num != i)
		// { 
		// 	if(d.find(i) == i)
		// 		ans = max(ans, d.rating[i] ^ mx);
		// }
		// cout << '\n' << ans << '\n';
		// if(ans == -1)	ans = mx;
		// ans = __builtin_popcount(ans);
		int ans;
		if(v.size() == 1)
			ans = __builtin_popcount(v[0]);
		else
		{
			ans = 0;
			int m = v.size();
			for(int i = 0; i < m; i++) {
				// cout << v[i] << ' ';
				for(int j = i + 1; j < m; j++) {
					ans = max(ans, __builtin_popcount( v[i] ^ v[j] ));
				}
			}
		}
		cout << ans << '\n';
	}
}