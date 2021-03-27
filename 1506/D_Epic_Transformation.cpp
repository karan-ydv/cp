#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n];	for(int& x: a)	cin >> x;
		sort(a, a + n);
		map<int, int> mp;
		for(int i = 0 ; i < n; i++) {
			int x;	cin >> x;
			mp[x]++;
		}
		multiset<int> s;
		for(auto [x, f]: mp) {
			s.insert(f);
		}
		while(s.size() > 1)
		{
			auto i1 = s.begin();
			auto i2 = --s.end();
			int a = *i1, b = *i2;
			s.erase(i1);
			s.erase(i2);
			if(b - a)
			{
				s.insert(b - a);
			}
		}
		int ans = 0;
		if(s.size()) {
			ans = *s.begin();
		}
		cout << ans << '\n';
	}
}