#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;	cin >>  n >> q;
	map<int, int> mp;
	for(int i = 1; i <= n; i++)
	{
		int x;	cin >> x;
		if(!mp.count(x)) {
			mp[x] = i;
		}
	}
	vector<int> ans;
	while(q--)
	{
		int x;	cin >> x;
		int i = mp[x];
		ans.emplace_back(i);
		
		for(auto [c, f]: mp)
		if(f < i)	mp[c] += 1;

		mp[x] = 1;
	}
	for(int x: ans)	cout << x << ' ';
}