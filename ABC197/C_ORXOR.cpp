#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n];	for(int &x: a)	cin >> x;
	int p = 1 << (n);
	int ans = 1LL << 60;
	for(int i = 0; i <= p; i++)
	{
		bitset<21> b(i);
		int val = 0, x = 0;
		for(int j = 0; j < n; j++) 
		{
			x |= a[j];
			if(b[j]) 
			{
				val ^= x;
				x = 0;
			}
		}
		val ^= x;
		ans = min(ans, val);
	}
	cout << ans;
}