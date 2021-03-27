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
		string s;
		int n;	cin >> n >> s;
		int pref[n + 2], suff[n + 2];
		pref[0] = 0;
		for(int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + (s[i - 1] == '0');
		}
		suff[n + 1] = 0;
		for(int i = n; i > 0; i--) {
			suff[i] = suff[i + 1] + (s[i - 1] == '1');
		}
		int ans  = 1 << 30;
		for(int i = 0; i <= n; i++) {
			ans = min(ans, n - pref[i] - suff[i + 1]);
		}
		cout << ans << '\n';
	}
}