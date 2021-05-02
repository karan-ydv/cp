#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x;
		int b[n];	for(int &x: b)	cin >> x;
		sort(a, a + n);
		sort(b, b + n, greater<int>());
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			// cout << a[i] << ' ' << b[i] << '\n';
			ans = max(ans, a[i] + b[i]);
		}
		cout << ans << '\n';
	}
}