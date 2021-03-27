#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, x, y;	cin >> a >> x >> y;
	if(y % a == 0)	return cout << "-1", 0;
	int p = y / a;
	if(p == 0)
	{
		if(2 * x < a and 2 * x > -a)
			cout << "1";
		else
			cout << "-1";
	}
	else
	{
		p--;
		int n = 2;
		n += (p + 1) / 2;
		n += 2 * (p / 2);
		if(p & 1)
		{
			if(x < a and x > 0)			cout << n + 1;
			else if(x < 0 and x > -a)	cout << n;
			else						cout << "-1";
		}
		else
		{
			if(2 * x < a and 2 * x > -a)
				cout << n;
			else
				cout << "-1";
		}
	}
}