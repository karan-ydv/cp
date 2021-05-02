#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n){
	int p = 1;
	while(n)
	{
		if(n & 1)	p = p * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return p;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int a, b, c;	cin >> a >> b >> c;
		int ans = modexp(modexp(a, b), c);
		cout << ans << '\n';
	}
}