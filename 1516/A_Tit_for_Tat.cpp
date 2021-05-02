#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, k;	cin >> n >> k;
		int a[n];	for(int &x: a)	cin >> x;
		int i = 0;
		while(k > 0 and i < n - 1)
		{
			int d = min(k, a[i]);
			k -= d;
			a[i] -= d;
			a[n - 1] += d;
			i++;
		}
		for(int x: a)	cout << x << ' ';	cout << '\n';
	}
}