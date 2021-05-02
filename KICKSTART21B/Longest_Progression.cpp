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
	for(int _ = 1; _ <= t; _ ++)
	{
		int ans = 1, n;	cin >> n;
		int a[n + 2] = {0};
		FOR(i, 1, n)	cin >> a[i];

		if(n == 2 or n == 3)
		{
			ans = n;
			cout << "Case #" << _ << ": " << ans << '\n';
			continue;
		}

		int pref[n + 2] = {0};
		int suff[n + 2] = {0};
		pref[1] = suff[n] = 1;
		pref[2] = suff[n - 1] = 2;

		FOR(i, 2, n)
		{
			pref[i] = 2;
			if(a[i] - a[i - 1] == a[i - 1] - a[i - 2])
				pref[i] = pref[i - 1] + 1;
			ans = max(ans, pref[i]);
		}

		ROF(i, n - 2, 1)
		{
			suff[i] = 2;
			if(a[i] - a[i + 1] == a[i + 1] - a[i + 2])
				suff[i] = suff[i + 1] + 1;
			ans = max(ans, suff[i]);
		}

		ans = max(ans, suff[2] + 1);		// if 1 is replaced
		ans = max(ans, pref[n - 1] + 1);	// if n - 1 is replaced
		

		// if 2 is replaced
		int y = 2 * a[3] - a[4];
		int x = (a[1] + a[3]) / 2;
		if(x == y)	ans = max(ans, suff[3] + 2);
		else		ans = max(ans, suff[3] + 1);

		// if n - 1 is replaced
		x = 2 * a[n - 2] - a[n - 3];
		y = (a[n] + a[n - 2]) / 2;
		if(x == y)	ans = max(ans, pref[n - 2] + 2);
		else		ans = max(ans, pref[n - 2] + 1);

		FOR(i, 3, n - 2)
		{
			ans = max(ans, pref[i - 1] + 1);
			ans = max(ans, suff[i + 1] + 1);

			int x = 2 * a[i - 1] - a[i - 2];
			int y = (a[i + 1] + a[i - 1]) / 2;
			int z = 2 * a[i + 1] - a[i + 2];

			if(x == z)
			if(x == y)	ans = max(ans, pref[i - 1] + suff[i + 1] + 1);
			if(x == y)	ans = max(ans, pref[i - 1] + 2);
			if(y == z)	ans = max(ans, suff[i + 1] + 2);
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}