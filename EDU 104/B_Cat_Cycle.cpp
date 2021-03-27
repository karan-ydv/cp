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
		if(n & 1)
		{
			int v1, v2;
			k = (k - 1) % (n * (n / 2)) + 1;
			if(k < n)
				v1 = (n + 1) / 2, v2 = n;
			else
			{
				int m = (n - 2);
				k -= (n - 1);
				v1 = k / m + (k % m != 0);	// ceil
				v2 = v1 + (n) / 2;
				k = (k - 1) % m + 1;
			} 
			if(k < v1)			cout << k << '\n';
			else if(k < v2)		cout << k + 1 << '\n';
			else				cout << k + 2 << '\n';
		}
		else
		{
			int x = (k - 1) % n + 1;
			cout << x << '\n';
		}
	}
}