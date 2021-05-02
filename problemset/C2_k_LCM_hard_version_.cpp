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
		int n, k;	cin >> n >> k;
		for(int i = 0; i < k - 3; i++) {
			cout << "1 ";
		}
		n -= k - 3;
		int a, b, c;
		if(n & 1)
		{
			a = 1;
			b = c = (n - 1) / 2;
		}
		else
		{
			if((n / 2) & 1)
			{
				a = 2;
				b = c = (n - 2) / 2;
			}
			else
			{
				a = n / 2;
				b = c = a / 2;
			}
		}
		cout << a << ' ' << b << ' ' << c << '\n';
	}
}