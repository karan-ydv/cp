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
		int n;	cin >> n;
		int ans = 0;
		// int up1, dn1, up2, dn2;
		// up1 = dn1 = up2 = dn2 = 0;
		for(int i = 0; i < n; i++)
		{
			int x;	cin >> x;
			ans += (x == 1) or (x == 3);
		}
		cout << ans << '\n';
	}
}