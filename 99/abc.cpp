#include <bits/stdc++.h>
#define int long long
using namespace std;

struct P
{
	typedef double type;
	type x, y;
	P(type a, type b) : x(a), y(b) {}
	void read()	{cin >> x >> y;}
	P operator -(const P& b) const {
		return P(x - b.x, y - b.y);
	}
	void operator -= (const P &b) {
		x -= b.x;	y -= b.y;
	}
	type operator * (const P& b) const {
		return x * b.y - y * b.x;
	}
	type Area(const P& b, const P& c) const {
		return 0.5 * abs(x * (b.y - c.y) + b.x * (c.y - y) + c.x * (y - b.y));
	}
};

double area(P a, P b, P c)
{
	return 0.5 * abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x  * (a.y - b.y));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	P a(2.5, 4), b(3, -6), c(0.7, 8.9);
	cout << area(a, b, c);
}