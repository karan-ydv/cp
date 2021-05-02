#include <bits/stdc++.h>
using namespace std;

int a, b, l;
const double pi = 3.14159265359;
const double delta = 0.0001;

struct P
{
	typedef double type;
	type x, y;
	P(type a, type b) : x(a), y(b) {}
	bool isLeft(P A, P B) {
		return (B.x - A.x) * (y - A.y) - (x - A.x) * (B.y - A.y) >= 0;
	}
};

P E(0, 0), O(0, 0);	// corner, origin
bool inside(double x, double w)
{
	double sx = sin(x), cx = cos(x);
	P A(l * cx, 0), D(0, l * sx);
	P B(A.x + w * sx, w * cx);
	P C(w * sx, D.y + w * cx);
	return E.isLeft(O, A) and E.isLeft(A, B) and E.isLeft(B, C) and E.isLeft(C, D) and E.isLeft(D, O);
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
	cout << fixed << setprecision(7);

	cin >> a >> b >> l;
	E.x = b, E.y = a;	// corner

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
	if(ans == -1) return cout << "My poor head =(", 0;
	
	beg = ans, end = min(ans + 1, min(a, l));
	for(int i = 0; i < 60; i++)
	{
		double mid = (beg + end) / 2;
		if(possible(mid))
			beg = mid;
		else
			end = mid;
	}
	cout << beg;
}