#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	n = n * 4 + 1;
	vector<int> a(n), b(n), c(n), d(n);
	for(int i = 0; i < n; i++)	cin >> a[i] >> b[i], c[i] = a[i], d[i] = b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int x1 = (a[0] == a[1] or a[0] == a[2]) ? a[0] : a[1];
	int y1 = (b[0] == b[1] or b[0] == b[2]) ? b[0] : b[1];
	int x2 = (a[n - 1] == a[n - 2] or a[n - 1] == a[n - 3]) ? a[n - 1] : a[n - 2];
	int y2 = (b[n - 1] == b[n - 2] or b[n - 1] == b[n - 3]) ? b[n - 1] : b[n - 2];
	int h = (x1 + x2), k = (y1 + y2), r = 2 * (x2 - x1);
	int x, y;
	for(int i = 0; i < n; i++)
	{
		x = 2 * c[i], y = 2 * d[i];
		if(abs(x - h + y - k) + abs(x - h - y + k) != r)
			break;
	}
	cout << x / 2 << ' ' << y / 2;
}