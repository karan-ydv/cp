#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	int a[1000006];
	a[0] = 0;
	int d = 2;
	for(int i = 1; i <= 1e6; i++)
	{
		a[i] = a[i - 1] + d;
		d += 2;
	}
	while(t--)
	{
		int n;	cin >> n;
		cout << a[n] << '\n';
	}
}