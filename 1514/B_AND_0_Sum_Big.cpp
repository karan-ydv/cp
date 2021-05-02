#include <bits/stdc++.h>
#define int int64_t
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
		int n, k;	cin >> n >> k;
		cout << modexp(n, k) << '\n';
	}
}