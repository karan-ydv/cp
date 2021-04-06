#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

int modexp(int a, int n){
	int p = 1;
	while(n)
	{
		if(n & 1)	p = p * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return p;
}

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
	int n;
	cin >> n;
	DSU dsu(n);
	for(int i = 1; i <= n; i++)
	{
		int x;	cin >> x;
		dsu.UNION(i, x);
	}
	set<int> set;
	for(int i = 1; i <= n; i++)
	{
		set.insert(dsu.find(i));
	}
	int ans = modexp(2, set.size()) + mod - 1;
	cout << ans % mod;
}