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
		int n, m, x;	cin >> n >> m >> x;
		int c = (x + n - 1) / n, r = (x - 1) % n;
		// cout << r << ' ' << c << '\n';
		int y = r * m + c;
		cout << y << '\n';
	}
}