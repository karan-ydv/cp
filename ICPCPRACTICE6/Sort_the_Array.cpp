#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+5;
int spf[N];

void seive()
{
	iota(spf,spf+N,0);
	spf[1]=1;
	int i,j;
	for(i=4;i<N;i+=2)  spf[i]=2;
	for(i=3;i*i<=N;i++)
	{
		if( spf[i]==i)
		for(j=i*i;j<N;j+=i)
		if(spf[j]==j)
			spf[j]=i;
	}
}

struct DSU {
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
	seive();
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		vector<int> a(n), b;
		for(int &x: a)	cin >> x;

		DSU dsu(n);
		map<int, int> mp;
		for(int i = 1; i <= n; i++)
		{
			map<int, int> m;
			int j = i;
			while(j != 1)
			{
				m[spf[j]]++;
				j /= spf[j];
			}

			int val = 1;
			for(auto [p, f]: m) {
				if(f & 1)	val *= p;
			}
			// cout << i << ' ' << val << '\n';
			if(mp[val] == 0) {
				mp[val] = i;
			}
			else
			{
				dsu.UNION(i, mp[val]);
			}
		}

		unordered_map<int, vector<int>> mpv;
		for(int i = 1; i <= n; i++)
		{
			mpv[dsu.find(i)].emplace_back(i - 1);
		}

		for(auto &[x, indx]: mpv)
		{
			vector<int> val;
			for(int i: indx)	val.emplace_back(a[i]);
			//  cout << i + 1 << ' ';
			sort(indx.begin(), indx.end());
			sort(val.begin(), val.end());
			int sz = indx.size();
			for(int i = 0; i < sz; i++)
			{
				a[indx[i]] = val[i];
			}
			// cout << '\n';
		}

		if(is_sorted(a.begin(), a.end()))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}