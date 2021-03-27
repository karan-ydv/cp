#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, d;	cin >> n >> m >> d;
	int a[n * m];
	for(int &x: a)	cin >> x;

	n *= m;
	int i;
	for(i = 1; i < n; i++) {
		if(a[i] % d != a[0] % d)
			break;
	}
	if(i < n)	return cout << "-1", 0;

	int ans = 1e9;
	for(i = 0; i < n; i++) {
		int x = 0;
		for(int j = 0; j < n; j++)
			x += abs(a[j] - a[i]) / d;
		ans = min(x, ans);
	}
	cout << ans;
}