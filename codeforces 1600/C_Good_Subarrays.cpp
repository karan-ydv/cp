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
		string s; int n;	cin >> n >> s;
		int pref[n + 2];
		pref[0] = 1e6;
		unordered_map<int, int> mp;
		for(int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + s[i - 1] - '0' - 1;
			mp[pref[i]]++;
		}
		pref[n + 1] = pref[n] + 1e6 - 1;
		mp[pref[n + 1]]++;
		int ans = 0;
		for(auto [a, b]: mp) {
			ans += b * (b - 1) / 2;
		}
		cout << ans << '\n';
	}
}