#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n]; for(int &x: a)	cin >> x;
		int m;	cin >> m;
		int b[m]; for(int &x: b)	cin >> x;
		int x = 0, y = 0;
		int s1 = x, s2 = y;
		for(int i = 0; i < n; i++)
		{
			s1 += a[i];
			x = max(s1, x);
		}
		for(int i = 0; i < m; i++)
		{
			s2 += b[i];
			y = max(s2, y);
		}
		cout << x + y << '\n';
	}
}