#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int ans = 0, x, y;	cin >> y;
	for(int i = 1; i < n; i++) {
		cin >>  x;
		ans += max(0LL, y - x);
		y = max(x, y);
	}
	cout << ans;
}