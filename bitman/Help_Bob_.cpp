#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	int x = 1 << (k - 1);
	int ans = 0;
	int a[n + 1] = {0};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		int v = a[i] ^ a[i - 1];
		bitset<30> b(v);
		ans += b[k - 1];
	}
	cout << ans;
}