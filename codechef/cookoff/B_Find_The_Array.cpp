#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n], b[n];
		for(int& x: a)	cin >> x;
		for(int i = 0; i < n; i++) {
			b[i] = 1 << (31 - __builtin_clz(a[i]));
		}
		for(int x: b)	cout << x << ' ';
		cout << '\n';
	}
}