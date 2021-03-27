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
		int x1, y1;		cin >> x1 >> y1;
		int x2, y2;		cin >> x2 >> y2;
		int x3, y3;		cin >> x3 >> y3;
		int x, y;
		if(x1 != x2 and x1 != x3)	x = x1;
		if(x2 != x1 and x2 != x3)	x = x2;
		if(x3 != x2 and x3 != x1)	x = x3;

		if(y1 != y2 and y1 != y3)	y = y1;
		if(y2 != y1 and y2 != y3)	y = y2;
		if(y3 != y2 and y3 != y1)	y = y3;

		cout << x << ' ' << y << '\n';
	}
}