#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; string a, b;
	cin >> n >> a;
	b = a.substr(n);
	a = a.substr(0, n);
	int q; cin >> q;
	while(q--)
	{
		int x, i, j;
		cin >> x >> i >> j;
		if(--x)
		{
			a.swap(b);
		}
		else
		{
			i--, j--;
			if(j < n)
			{
				swap(a[i], a[j]);
			}
			else if(i >= n)
			{
				i -= n, j -= n;
				swap(b[i], b[j]);
			}
			else
			{
				j -= n;
				swap(a[i], b[j]);
			}
		}
	}
	cout << a << b;
}