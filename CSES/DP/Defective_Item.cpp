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
		int n, q;	cin >> n >> q;
		unordered_map<int, int> mp;
		int a[n], sum[n];
		for(int i = 0; i < n; i++)
			cin >> a[i], mp[a[i]] = i;
		partial_sum(a, a + n, sum);
		while(q--)
		{
			int x;	cin >> x;
			int i = mp[x];
			int ans = min(sum[i], sum[n - 1] - (i > 0 ? sum[i - 1] : 0));
			cout << ans << '\n';
		}
	}
}