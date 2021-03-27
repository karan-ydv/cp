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
		int n, m;	cin >> n >> m;
		vector<int> v(n), one, two;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}

		for(int i = 0; i < n; i++) {
			int x;	cin >> x;
			if(x == 1)	one.emplace_back(v[i]);
			if(x == 2)	two.emplace_back(v[i]);
		}

		int p = one.size(), q = two.size();
		sort(one.begin(), one.end(), greater<int>());
		sort(two.begin(), two.end(), greater<int>());

		int c[p + 1], d[q + 1];	c[0] = 0; d[0] = 0;
		partial_sum(one.begin(), one.end(), c + 1);
		partial_sum(two.begin(), two.end(), d + 1);

		int beg = 1, end = 2 * q + p, mid, ans = -1;
		auto possible = [&](int mid) {
			
			for(int i = 0; i <= min(mid, p); i++)
			{
				int s = c[i];
				int j = (mid - i) / 2;
				if(j <= q)	s += d[j];
				if(s >= m)	return true;
			}
			return false;
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