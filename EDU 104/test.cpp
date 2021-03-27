#include <bits/stdc++.h>
#define int long long
using namespace std;

int fun(int n)
{
	int l = 1, r = n, c = 0;
	// cout << l << ' ';
	do
	{
		l++;
		r--;
		if(l > n)	l = 1;
		if(r < 1)	r = n;
		if(l == r)
		{
			l++;
			if(l > n) l = 1;
		}
		c++;
		// cout << '(' << c + 1 << ' ' << (c - 67 - 1) % 67 + 1 << ' ' << l << ' ' << r << ") ";
		cout << l << ' ';
		if(c % (n - 2) == 0)	cout  << '\n';
		//  << r << '\n';
		// if(c > 100)	break;
	}
	while(!(l == 1 and r == n));
	// cout << c << '\n';
	return c -1;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	// for(int i = 3; i < 20; i+= 2) {
	// 	cout << i << ' ' << fun(i) << '\n';
	// }
	fun(n);
}