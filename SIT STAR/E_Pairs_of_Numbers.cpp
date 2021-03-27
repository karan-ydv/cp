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
		if(gcd(x, y) != 1)
		{
			cout << "-1\n";
			continue;
		}
		int ans = -1;
		while(x > 0 and y > 0)
		{
			if(x > y)	swap(x, y);
			ans += y / x;
			y  %= x;
		}
		cout << ans << '\n';
	}
}