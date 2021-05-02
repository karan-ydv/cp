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
		int n, x;	cin >> n >> x;
		map<int, int> mp;
		for(int i = 0; i < n; i++)
		{
			int v;	cin >> v;
			mp[v]++;
		}
		int cnt = 0;
		for(auto [v, f]: mp)
		{
			cnt += f - 1;
			mp[v] = 1;
		}
		int ans = mp.size() - max(0ll, x - cnt);
		cout << ans << '\n';
	}
}