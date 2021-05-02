#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) begin(x), end(x)

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n]; for(int &x: a)	cin >> x;
	sort(a, a + n);
	int ans = 0, m = n / 2;
	for(int x: a)	ans += abs(x - a[m]);
	cout << ans;
}