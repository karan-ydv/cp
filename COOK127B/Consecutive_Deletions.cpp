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
		int n, k;	cin >> n >> k; 
		int a[n];	for(int &x: a)	cin >> x;
		int pref[n + 1] = {0};
		for(int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + a[i - 1];
		}
		int ans = 1e18;
		for(int i = k; i <= n; i++) {
			// cout << ans << '\n';
			int tmp = pref[i] - pref[i - k];
			if(tmp <= 1) {
				ans = pref[n];
				break;
			}
			else {
				int x = pref[n] - pref[i] + pref[i - k] + tmp * (tmp + 1) / 2;
				ans = min(ans, x);
			}
		}
		cout << ans << '\n';
	}
}