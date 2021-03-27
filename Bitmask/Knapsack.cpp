#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int a[n], b[m];
	for(int &x: a)	cin >> x;
	for(int &x: b)	cin >> x;
	sort(b, b + m);
	sort(a, a + n, greater<int>());

	int ans = accumulate(a, a + m, 0LL);
	int j = m - 1;
	for(int i = 0; i < m; i++) {
		if(b[i] == 1) {
			ans += a[i];
		}
		else {
			j += b[i] - 1;
			ans += a[j];
		}
	}
	cout << ans;
}