#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#define FOR(i, j, k) for(int32_t i = j; i <= k; i++)
#define ROF(i, j, k) for(int32_t i = j; i >= k; i--)

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int ans = 1;
		int n;	cin >> n;
		int a[n + 2] = {0}, pref[n + 2] = {0}, suff[n + 2] = {0};
		FOR(i, 1, n)	cin >> a[i];
		pref[1] = suff[n] = 1;
		a[0] = 2 * a[1] - a[2];
		a[n + 1] = 2 * a[n] - a[n - 1];
		FOR(i, 2, n - 1)
		{
			pref[i] = 2;
			if(a[i] - a[i - 1] == a[i - 1] - a[i - 2])
			pref[i] = pref[i - 1] + 1;
			ans = max(ans, pref[i]);
		}
		ROF(i, n - 1, 1)
		{
			suff[i] = 2;
			if(a[i] - a[i + 1] == a[i + 1] - a[i + 2])
			suff[i] = suff[i + 1] + 1;
			ans = max(ans, suff[i]);
		}
		// FOR(i, 1, n)	cout << pref[i] << " \n"[i == n];
		// FOR(i, 1, n)	cout << suff[i] << " \n"[i == n];
		ans = max(ans, suff[2] + 1);
		ans = max(ans, pref[n - 1] + 1);
		FOR(i, 2, n - 1)
		{
			int x = (a[i + 1] + a[i - 1]) / 2;
			if(x - a[i - 1] == a[i - 1] - a[i - 2])
			if(a[i + 1] - x == a[i + 2] - a[i + 1])
			ans = max(ans, pref[i - 1] + suff[i + 1] + 1);
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}