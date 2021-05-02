#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c, n;	cin >> c >> n;
	int a[n];	for(int &x: a)	cin >> x;
	int mx = -1;
	for(int i = 1; i < n; i++)
	{
		mx = max(mx, a[i] - a[i - 1]);
	}
	mx = max(mx, a[0] + c - a[n - 1]);
	cout << c - mx;
}