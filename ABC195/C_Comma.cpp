#include <bits/stdc++.h>
#define int long long
using namespace std;

int comma(int l) {
	return (l - 1) / 3;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	string s = to_string(n);
	int l = s.length();
	int ans = 0, x = 1;
	for(int i = 1; i < l; i++) {
		ans += (x * 9) * comma(i);
		x *= 10;
	}
	ans += (n - x + 1) * comma(l);
	cout << ans;
}