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
			return cout << "NO\n", void();
		for(int rep = 0; rep < 2; rep++) {
			if(max(p1.x, p2.x) < min(p3.x, p4.x) or max(p1.y, p2.y) < min(p3.y, p4.y))
				return cout << "NO\n", void();
			swap(p1, p3);
			swap(p2, p4);
		}
		return cout << "YES\n", void();
	}

	for(int rep = 0; rep < 2; rep++) {
		int sign1 = (p2 - p1) * (p3 - p1);
		int sign2 = (p2 - p1) * (p4 - p1);
		if((sign1 < 0 and sign2 < 0) or (sign1 > 0 and sign2 > 0))
			return cout << "NO\n", void();
		swap(p1, p3);
		swap(p2, p4);
	}
	cout << "YES\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		testcase();
	}
}