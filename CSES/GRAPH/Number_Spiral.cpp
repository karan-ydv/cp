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
		int x, y, z;	cin >> x >> y;
		if(y > x)	swap(x, y);
		if(x & 1)
			z = (x - 1) * (x - 1) + y;
		else
			z = x * x - y + 1;
		cout << z << '\n';
	}
}