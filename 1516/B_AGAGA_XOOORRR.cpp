#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, z = 0;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x, z ^= x;
		bool flag = (z == 0);
		if(!flag)
		{
			int x = 0, c = 0;
			for(int y: a)
			{
				x ^= y;
				if(x == z)
					c++, x = 0;
			}
			flag = c > 2 and x == 0;
		}
		if(flag)	cout << "YES\n";
		else		cout << "NO\n";
	}
}