#include <bits/stdc++.h>
#define int long long
using namespace std;

struct P {
	int x, y;
	P() {}
	P(int a, int b) : x(a), y(b) {}
    void read() {
		cin >> x >> y;
	}
	P operator -(const P& b) const {
		return P(x - b.x, y - b.y);
	}
	void operator -=(const P& b) {
		x -= b.x;
		y -= b.y;
	}
	int operator *(const P& b) const {
		return x * b.y - y * b.x;
	}
	int triangle(const P&b, const  P& c) const {
		return (b - *this) * (c - *this);
	}
};

void testcase() {
	P p1, p2, p3, p4;
	p1.read();
	p2.read();
	p3.read();
	p4.read();

	if((p2 - p1) * (p4 - p3) == 0) {
		if(p1.triangle(p2, p3) != 0)
			return cout << "NONE\n", void();
		return cout << "LINE\n", void();
	}

	cout << "POINT ";
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(2) << fixed;
	int t;	cin >> t;
	cout << "INTERSECTING LINES OUTPUT\N";
	while(t--)
	{
		testcase();
	}
	cout << "END OF OUTPUT";
}
