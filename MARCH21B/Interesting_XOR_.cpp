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
		int c;	cin >> c;
		int x = 1LL << (63 - __builtin_clzll(c));
		int a = x, b = c ^ x;
		while(x)
		{
			if(!(c & x))
			{
				a |= x;
				b |= x;
			}
			x >>= 1;
		}
		int ans = a * b;
		cout << ans << '\n';
	}
}