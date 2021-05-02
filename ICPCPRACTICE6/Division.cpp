#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int k, a, b;	cin >> k >> a >> b;
		int sum = 0;
		// cout << a/b << '.';
		a %= b;
		for(int i = 0; i < k; i++)
		{
			a *= 10;
			// cout << a / b;
			sum += a / b;
			a %= b;
		}
		cout << sum << '\n';
	}
}