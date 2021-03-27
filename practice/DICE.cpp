#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n) {
	int r = 1;
	while(n)
	{
		if(n & 1)	r = (r * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return r;
}

int sumofgp(int a, int r, int n)
{
	int res = (modexp(r, n) + mod - 1) % mod * a % mod;
	res *= modexp(r - 1, mod - 2);
	return res % mod;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("dice.in", "r", stdin);
	int t;	cin >> t;
	while(t--)
	{
		int n, k, r, m;
		cin >> n >> k >> r >> m;
		
		int A = modexp(r - 1, k - 1) * modexp(modexp(r, k), mod - 2) % mod;
		int R = modexp(r - 1, n) * modexp(modexp(r, n), mod - 2) % mod;

		int ans = sumofgp(A, R, m);
		cout << ans << '\n';
	}
}