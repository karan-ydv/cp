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
		int x, y;	cin >> x >> y;
		// for(int i = 1;)
		int ans = min((x - 1) * 20, 5 * (abs(y - 1) + x - 1));
		cout << ans << '\n';
	}
}