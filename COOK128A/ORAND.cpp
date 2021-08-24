#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, q;	cin >> n >>	q;
		int a[n];	for(int &x: a)	cin >> x;
		int f[32] = {0};
		int ans = 0;
		for(int x: a)
		{
			ans |= x;
			int bit = 1;
			for(int j = 0; j < 32; j++)
			{
				if((x & bit))	// if j-th bit is set in x
					f[j]++;
				bit <<= 1;
			}
		}
		cout << ans << '\n';
		while(q--)
		{
			int x, val;	cin >> x >> val;
			x--;
			ans = 0;
			int bit = 1;
			for(int j = 0; j < 32; j++)
			{
				if(a[x] & bit)	f[j]--;
				if(val & bit)	f[j]++;
				if(f[j] > 0)	ans |= bit;
				bit <<= 1;
			}
			a[x] = val;
			cout << ans << '\n';
		}
	}
}