#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, sum;	cin >> n >> sum;
	int a[n], b[n];
	int mn = 0, mx = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		mn += a[i], mx += b[i];
	}
	if(sum < mn or sum > mx) {
		return cout << "NO", 0;
	}
	int ans[n];
	for(int i = 0; i < n; i++) {
		ans[i] = a[i];
	}
	sum -= mn;
	for(int i = 0; i < n and sum > 0; i++) {
		int x = b[i] - a[i];
		ans[i] += min(x, sum);
		sum -= x;
	}
	cout << "YES\n";
	for(int x: ans)	cout << x << ' ';
}