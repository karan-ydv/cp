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
		int n, m , k;	cin >> n >> m >> k;
		int ans = 0;
		if(m < n)	swap(n, m);
		int f = 1;
		for(int i = 2; i <= n + 1; i++, f++) {
			if((f & 1)) {
				ans ^= (k + i);
				// cout << k + i << '\n';
			}
			// cout << i << ' ' << f << '\n';
		}
		// cout << '\n';
		f--;
		for(int i = n + 2; i <= m + 1; i++) {
			if((f & 1)) {
				ans ^= (k + i);
				// cout << k + i << '\n';
			}
			// cout << i << ' ' << f << '\n';
		}
		f--;
		for(int i = m + 2; i <= n + m; i++, f--) {
			if((f & 1)) {
				// cout << k + i << '\n';
				ans ^= (k + i);
			}
			// cout << i << ' ' << f << '\n';
		}
		// cout << '\n';
		cout << ans << '\n';
	}
}