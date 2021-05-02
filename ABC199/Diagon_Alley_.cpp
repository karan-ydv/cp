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
		int a, b, k;	cin >> a >> b >> k;
		int x = (k + 1) / 2;
		int ans = x * a - b * (k - x);
		cout << ans << '\n';
	}
}