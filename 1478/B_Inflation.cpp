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
		int ans, beg = 0, end = 1e18, mid;
		int p[n];	for(int &x: p)	cin >> x;
		partial_sum(p, p + n, p);
		auto possible = [&](int m) {
			
		};
		while(beg <= end)
		{
			mid = beg + end >> 1;
			if(possible(mid))
				ans = mid, end = mid - 1;
			else
				beg = mid + 1;
		}
		cout << ans <<  '\n';
	}
}