#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n], b[n];
	int ans = 2e9;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		ans = min(ans, a[i] + b[i]);
	}
	for(int i = 0; i < n; i++)
	{
		int t = 2e9, u = 2e9;
		for(int j = 0; j < n; j++)
		if(j != i)
		t = min(t, b[j]), u = min(u, a[j]);
		ans = min(max(a[i], t), ans);
		ans = min(max(b[i], u), ans);
	}
	cout << ans;
}