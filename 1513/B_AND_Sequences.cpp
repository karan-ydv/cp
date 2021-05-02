#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n]; for(int &x: a)	cin >> x;
		int pref[n + 2], suff[n + 2];
		suff[n + 1] = pref[0] = (1 << 30) - 1;
		for(int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] & a[i - 1];
		}
		for(int i = n; i >= 1; i--) {
			suff[i] = suff[i + 1] & a[i - 1];
		}
		int c = 0;
		map<int, int> mp;
		for(int i = 1; i <= n; i++) {
			if(a[i - 1] == (pref[i - 1] & suff[i + 1]))
				mp[a[i - 1]]++;
		}
		int ans = 0;
		int fac = 1;
		for(int i = 2; i <= n - 2; i++) {
			fac = fac * i % mod;
		}
		for(auto [x, f]: mp) {
			ans += (f * (f - 1) % mod) * fac % mod;
			ans %= mod;
		}
		cout << ans << '\n';
	}
}