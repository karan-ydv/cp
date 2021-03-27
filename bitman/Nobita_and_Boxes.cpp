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
		int l, b, h, n;
		cin >> l >> b >> h >> n;
		
		int beg = 1, end = 1e6, mid, ans;
		auto possible = [&](int m) {
			int x = m / l;
			int y = m / b;
			int z = m / h;
			return x * y * z >= n;
		};
		while(beg <= end)
		{
			mid = beg + end >> 1;
			if(possible(mid))
				ans = mid, end = mid - 1;
			else
				beg = mid + 1;
		}
		cout << ans << '\n';
	}
}