#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n];	for(int &x: a)	cin >> x;
	int sum = accumulate(a, a + n, 0ll);
	int mx = *max_element(a, a + n);
	int ans = max(mx, (sum + n - 2) / (n - 1));
	cout << ans;
}