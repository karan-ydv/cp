#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

int modexp(int a, int n)
{
	int r = 1;
	while(n)
	{
		if(n & 1) r *= a, r %= mod;
		a *= a, a %= mod;
		n >>= 1;
	}
	return r;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		int d = b - a;
		int x = (c - b) / d;
		// cout << d << ' ' << x << endl;

		int ans = (modexp(x, n - 1) + mod - 1) % mod * d % mod;
		ans *= modexp(x - 1, mod - 2);
		ans %= mod;
		ans = (ans + a) % mod;

		int z = (modexp(x, n - 1) + mod - 1) % mod * x % mod;
		z *= modexp(x - 1, mod - 2);
		z %= mod;
		z = (z + mod + 1 - n) % mod * d % mod;
		z *= modexp(x - 1, mod - 2);
		z %= mod;
		z += a * n % mod;
		z %= mod;
		cout << ans << ' ' << z << '\n';
	}
}