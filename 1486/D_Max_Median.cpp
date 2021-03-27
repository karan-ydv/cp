#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	int a[n];	for(int &x: a)	cin >> x;

	auto possible = [&](int m) {
		int pref[n + 1] = {0};
		for(int i = 1; i <= n; i++) {
			pref[i] = a[i - 1] < m ? -1 : 1;
			pref[i] += pref[i - 1];
		}
		int mn = 0;
		for(int i = k; i <= n; i++) {
			if(pref[i] - mn > 0)	return true;
			mn = min(mn, pref[i - k + 1]);
		}
		return false;
	};
	int beg = 1, end = n, ans;
	while(beg <= end)
	{
		int mid = beg + end >> 1;
		if(possible(mid)) {
			ans = mid;
			beg = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans;
}