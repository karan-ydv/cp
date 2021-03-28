#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

int modexp(int a, int n)
{
	int r = 1;
	while(n)
	{
		if(n & 1)	r = r * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return r;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;		cin >> n;
	int a[n + 1];
	int ans = 0;
	for(int i = 1; i <= n; i++)	
	cin >> a[i], ans += a[i] * a[i], ans %= mod;
	sort(a + 1, a + n + 1);

	int pref[n + 1] = {0}, pw = 1;
	for(int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i] * pw % mod;
		// cout << pref[i] << ' ';
		pw = pw * 2 % mod;
	}
	// cout << '\n';

	pw = 2;
	for(int i = 1; i < n; i++)
	{
		int x = (pref[n] - pref[i] + mod) % mod * modexp(pw, mod - 2) % mod;
		// cout << x << ' ';
		ans = (ans + a[i] * x % mod) % mod;
		pw = pw * 2 % mod;
	}
	// cout << '\n';

	cout << ans;
}