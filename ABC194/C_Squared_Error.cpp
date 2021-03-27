#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;			cin >> n;
	int a[n];		for(int &x: a)	cin >> x;
	int b[n] = {a[0]};
	for(int i = 1; i < n; i++)
		b[i] = b[i - 1] + a[i];
	int ans = a[0] * a[0] * (n - 1);
	for(int i = 1; i < n; i++) {
		ans += a[i] * a[i] * (n - 1);
		ans -= 2 * a[i] * (b[i - 1]);
	}
	cout << ans;
}