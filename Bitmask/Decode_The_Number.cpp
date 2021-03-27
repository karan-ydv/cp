#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	map<pair<int, int>, int> mp;
	for(int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		mp[{a, b}]++;
		mp[{a, 1 - b}] += 0;
	}
	int ans = 0;
	for(auto [x, f0]: mp) {
		auto [a, b] = x;
		if(b == 0) {
			int f1 = mp[{a, 1}];
			if(f0 > f1) {
				ans -= a * f0;
			}
			else ans += a * f1;
		}
	}
	cout << ans;
}