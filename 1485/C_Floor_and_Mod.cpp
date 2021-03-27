#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int a, b;	cin >> a >> b;
		int ans = 0;
		for(int i = 2; i <= min(a, b); i++) {
			ans += min(i - 1, a / (i + 1));
		}
		cout << ans << '\n';
	}
}