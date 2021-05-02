#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int extended_euclidean(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int modinverse(int a, int m)
{
	int x, y;
	int g = extended_euclidean(a, m, x, y);
	if (g != 1) {
		return -1;
		cout << "No solution!";
	}
	else {
		x = (x % m + m) % m;
		return x;
		// cout << x << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	int i =9240;
	for(int j = 2; j < i; j++)
		if(modinverse(j, i) == j)	cout << j << ' ';
	// int i = 100000;
	// for(int i = 2; i <= 1e4; i++)	
	// {
	// 	int c = 0;
	// 	ans = max(ans, c);
	// }
	// cout << ans;
}