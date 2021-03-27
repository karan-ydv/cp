#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
const int mod =  1e9+7;
int fact[N], factinv[N];

int modexp(int a, int n) {
	int x = 1;
	while(n)
	{
		if(n & 1)	x = x * a % mod;
		n >>= 1;
		a = a * a % mod;
	}
	return x;
}

int ncr(int n, int r) {
	int ret = fact[n] * factinv[r] % mod;
	return ret * factinv[n - r] % mod;
}

void preprocess() {
	fact[0] = 1;
	factinv[0] = 1;
	for(int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i % mod;
		factinv[i] = modexp(fact[i], mod - 2);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	preprocess();
	int n, m;	cin >> n >> m;
	int f[n];	for(int &x: f)	cin >> x;
	int sum = accumulate(f, f + n, 0LL);
	sum %= mod;
	while(m--)
	{
		int x;	cin >> x;
		int ans = 0;
		if(x < n)
		{
			int val = fact[x] * fact[n - x] % mod;
			x = ncr(n - 1, x) * val % mod;
			ans = sum * x % mod;
			ans = ans * factinv[n] % mod;
		}
		cout << ans << '\n';
	}
}