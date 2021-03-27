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
		int n, k;	cin >> n >> k;
		int a[n];
		for(int i = 1; i <= k; i++)		a[i - 1] = i;
		for(int i = 1; i <= n - k; i++)	a[k + i - 1] = k - i;

		int inv = (n - k) * (n - k + 1) / 2;
		int p[k];
		for(int i = 0; i < n; i++)
		{
			if(inv >= n - i - 1)
			{
				p[]
			}
		}
		for(int &x: p)	cout << x << ' ';
		cout << '\n';
	}
}