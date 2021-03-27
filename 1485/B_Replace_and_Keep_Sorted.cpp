#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q, k;	cin >> n >> q >> k;
	int a[n + 2];
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 0; a[n + 1] = k + 1;
	int pref[n + 1] = {0};
	for(int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		pref[i] += a[i + 1] - a[i - 1] - 2;
	}
	while(q--)
	{
		int l, r;	cin >> l >> r;
		if(l == r)
		{
			cout << k - 1 << '\n';
			continue;
		}
		int s = pref[r - 1] - pref[l];
		s += a[l + 1] - 2;
		s += k - 1 - a[r - 1];
		cout << s << '\n';
	}
}