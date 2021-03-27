#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7+5;
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

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	seive();
	int t;	cin >> t;
	while(t--)
	{
		int n, k;	cin >> n >> k;
		int a[n];	for(int &x: a)	cin >> x;
		auto vectorhash = [](vector<int> &vec) {
			int seed = vec.size();
			for(auto& i : vec) {
				seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		};
		int ans = 1;
		unordered_set<int> st;
		for(int x: a)
		{
			vector<int> v;
			unordered_map<int, int> mp;
			int j = x;
			while(j != 1)
			{
				mp[spf[j]]++;
				j /= spf[j];
			}
			for(auto [p, f]: mp) {
				if(f & 1)	v.emplace_back(p);
			}
			if(v.empty()) {
				v.emplace_back(1);
			}
			int hs = vectorhash(v);
			if(st.count(hs)) {
				ans++;
				st = unordered_set<int>();
			}
			st.insert(hs);
		}
		cout << ans << '\n';
	}
}