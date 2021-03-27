#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pi 3.141592653589793238462643383279502884L

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	int n;	cin >> n;

	long double x0, y0, x1, y1, xn, yn, cx, cy;
	cin >> x0 >> y0 >> xn >> yn;
	long double r = sqrt(pow(xn - x0, 2) + pow(yn - y0, 2)) / 2;
	cx = (x0 + xn) / 2;
	cy = (y0 + yn) / 2;
	x0 -= cx;
	y0 -= cy;

	long double theta = atan2(y0, x0) + (2 * pi / n);
	x1 = cx + r * cos(theta);
	y1 = cy + r * sin(theta);
	
	cout << x1 << ' ' << y1;
}