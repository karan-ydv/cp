#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int w, n;	cin >> w >> n;
		int a[w + 1] = {0}, pref[w + 1];
		for(int i = 1; i <= w; i++)	cin >> a[i];
		sort(a, a + w);
		partial_sum(a, a + w + 1, pref);

		auto getSum = [&](int i, int j) {
			return pref[j] - pref[i - 1];
		};
		auto GetMin = [&](int i) {
			int beg = 1, end = i, j;
			while(beg <= end)
			{
				int mid = beg + end >> 1;
				if(a[i] - a[mid] < n + a[mid] - a[i]) {
					end = mid - 1;
					j = mid;
				}
				else {
					beg = mid + 1;
				}
			}
			cout << "j = " << j << '\n';
			int ret = a[i] * (i - j + 1) - getSum(j, i);
			if(j != 1)
			ret += n * (j - 1) + getSum(1, j - 1) - (j - 1) * a[i];
			beg = i, end = w;
			while(beg <= end)
			{
				int mid = beg + end >> 1;
				if(a[mid] - a[i] < n + a[i] - a[mid]) {
					beg = mid + 1;
					j = mid;
				}
				else {
					end = mid - 1;
				}
			}
			cout << "j = " << j << '\n';
			ret += getSum(i, j) - (j - i + 1) * a[i];
			if(j != w)
			ret += (a[i] + n) * (w - j - 1) - getSum(j + 1, w);
			return ret;
		};

		int ans = 1e18;
		for(int i = 1; i <= w; i++) {
			// cout << GetMin(i) << '\n';
			ans = min(ans, GetMin(i));
		}
		cout << "Case #" << _ << ": ";
		cout << ans << '\n';
	}
}