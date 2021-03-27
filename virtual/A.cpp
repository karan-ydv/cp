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
		n += 2;
		int a[n + 1];
		a[0] = 0;
		a[1] = 1;
		a[2] = 1;
		for(int i = 3; i <= n; i++) {
			a[i] = a[i - 1] + a[i - 2] + a[i - 3];
		}
		cout << a[n] << '\n';
	}
}