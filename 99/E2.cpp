#include <bits/stdc++.h>
#define int long long
using namespace std;


int a, b, l;
const double pi = 3.14159265359;
const double delta = 0.0001;

bool inside(double x, double w)
{
	double x1 = l * sin(x) + w / cos(x), y1 = 0;
	double x2 = 0, y2 = l * cos(x) + w / sin(x);
	return (x2 - x1) * (a - y1) - (y2 - y1) * (b - x1) > 0;
}

bool possible(double w)
{
	double theta = delta;
	while(theta < pi / 2)
	{
		if(inside(theta, w))
			return false;
		theta += delta;
	}
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> l;
		cout << fixed << setprecision(7);
	if(l <= b)
	{
		double ans = min(l, a);
		return cout << ans, 0;
	}
	double beg = 0, end = min(a, l);
	int ans = -1;
	while(beg <= end)
	{
		int mid = (beg + end) / 2;
		if(possible(mid))
			beg = mid + 1, ans = mid;
		else
			end = mid - 1;
	}
	if(ans == -1)
		return cout << "My poor head =(", 0;
	beg = ans, end = min(ans + 1, min(a, l));
	for(int i = 0; i < 100; i++)
	{
		double mid = (beg + end) / 2;
		if(possible(mid))
			beg = mid;
		else
			end = mid;
	}
	cout << beg;
}