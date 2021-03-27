#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int fun(int x)
{
	int r = 0;
	for(int i = 0; i < n; i++) {
		r *= 10;
		if(x & 1)	r += 1;
		else		r += 2;
		x >>= 1;
	}
	return r;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int m = 1 << n;
	for(int i = 0; i < m; i++) {
		int x = fun(i);
		if(x % m == 0)
			return cout << x, 0;
	}
	cout << "-1";
}