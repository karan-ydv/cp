#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int c[n];	for(int& x: c)	cin >> x;
	int a[n];
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		a[i] = c[i] + mx;
		mx = max(mx, a[i]);
	}
	for(int x: a)	cout << x << ' ';
}