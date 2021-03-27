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
		int q[n + 1] = {0};
		for(int i = 0; i < n; i++) {
			cin >> q[i];
		}
		int ans = n + 1;
		for(int i = 0; i < n; i++) {
			if(q[i] < m) {
				ans = i + 1;
				break;
			}
			q[i + 1] += q[i] - m;
		}
		if(ans == n + 1)
		{
			ans += q[n] / m;
		}
		cout << ans << '\n';
	}
}