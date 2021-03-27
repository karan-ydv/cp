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
		int a, b;	cin >> a >> b;
		int beg = b, end = a + 1;
		auto f = [&](int m) {
			int res = m - b;
			if(m == 1) {
				return (int)2e9;
			}
			int x = a;
			while(x > 0) {
				x /= m;
				res ++;
			}
			// cout << m << ' ' << res << '\n';
			return res;
		};
		int ans = 2e9;
		while(beg < end)
		{
			int mid = (beg + end) >> 1;
			int x = f(mid), y = f(mid + 1);
			if(y < x) {
				beg = mid + 1;
				ans = min(ans, y);
			}
			else {
				ans = min(ans, x);
				end = mid;
			}
		}
		cout << ans << '\n';
	}
}