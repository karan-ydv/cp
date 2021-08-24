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
		int x, y;	cin >> x >> y;
		int sm = x + y;
		int n = sqrt(sm);
		int D = (2 * x - n * n);
		int d = sqrt(D);
		int e = (n + d) / 2;
		int o = n - e;
		if((d * d) != D or (d % 2) != (n % 2) or (e == n))
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << n << '\n';
		for(int i = 2; i <= o + 1; i++)
		{
			cout << "1 " << i << '\n';
		}
		for(int j = o + 2; j <= e + o; j++)
		{
			cout << "2 " << j << '\n';
		}
	}
}