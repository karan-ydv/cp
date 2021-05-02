#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		if(n % 2050 == 0)
		{
			n /= 2050;
			int ans = 0;
			while(n)
			{
				ans += n % 10;
				n /= 10;
			}
			cout << ans << '\n';
		}
		else cout << "-1\n";
	}
}