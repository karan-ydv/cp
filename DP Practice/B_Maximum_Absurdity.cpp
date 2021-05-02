#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#define FOR(i, j, k) for(int32_t i = j; i <= k; i++)
#define ROF(i, j, k) for(int32_t i = j; i >= k; i--)

#define f first
#define s second
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	int a[n + 2] = {0};
	FOR(i, 1, n)	cin >> a[i];
	partial_sum(a + 1, a + n + 1, a + 1);
	auto sum = [&](int i) {
		if(i + k - 1 > n or i < 1)	return 0ll;
		return a[i + k - 1] -  a[i - 1];
	};
	int pref[n + 2] = {0}, suff[n + 2] = {0};

	FOR(i, k, n)
	{
		pref[i] = pref[i - 1];
		if(sum(i - k + 1) > sum(pref[i - 1]))
			pref[i] = i - k + 1;
	}
	ROF(i, n - k + 1, 1)
	{
		suff[i] = suff[i + 1];
		if(sum(i) >= sum(suff[i + 1]))
			suff[i] = i;
	}
	int mx = 0, x, y;
	FOR(i, k, n - k)
	{
		if(sum(pref[i]) + sum(suff[i + 1]) > mx)
		{
			x = pref[i], y = suff[i + 1];
			mx = sum(pref[i]) + sum(suff[i + 1]);
		}
	}
	cout << x << ' ' << y;
}