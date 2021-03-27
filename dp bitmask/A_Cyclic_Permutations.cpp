#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

int modexp(int a, int n) {
	int r = 1;
	while(n) {
		if(n & 1)	r = (r * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return r;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int total = 1;
	for(int i = 2; i <= n; i++)
		total = (total * i) % mod;
	int ans = (total + mod - modexp(2, n - 1)) % mod;
	cout << ans;
}