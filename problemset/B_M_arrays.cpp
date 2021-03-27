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
		int n, m;	cin >> n >> m;
		map<int, int> mp;
		for(int i = 0; i < n; i++) {
			int x;	cin >> x;
			x %= m;
			mp[x]++;
		}
		if(mp.count(0))
			mp[0] = 1;
		int ans = 0;
		for(auto [a, f]: mp) {
			// cout << a << ' ' << f << '\n';
			if(mp.count(m - a) and mp[m - a]) {
				if(a + a == m) {
					ans ++;
				}
				else {
					ans ++;
					ans += max(0ll, max(f, mp[m - a]) - min(f, mp[m - a]) - 1);
				}
				mp[a] = 0;
				mp[m - a] = 0;
			}
			else {
				ans += f;
			}
		}
		cout << ans << '\n';
	}
}