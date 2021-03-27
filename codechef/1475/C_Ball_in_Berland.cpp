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
		int a, b, k;	cin >> a >> b >> k;
		pair<int, int> p[k];
		vector<int> boy(a + 1, 0), girl(b + 1, 0);
		for(auto &x: p)	cin >> x.first;
		for(auto &x: p) {
			cin >> x.second;
			boy[x.first]++;
			girl[x.second]++;
		}
		int ans = 0;
		for(auto [b, g]: p) {
			ans += k - girl[g] - boy[b] + 1;
		}
		ans /= 2;
		cout << ans << '\n';
	}
}