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
		int a[n], b[n], sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
			// bitset<32> bt(a[i]);
			// cout << bt.to_string() << endl;
			b[i] = ~a[i] + (-a[i] + 1);
			if(a[i] == 0)	b[i] = 1;
			// cout << b[i] << ' ';
		}
		cout << '\n';
		int ans = sum;
		int mx = 0, c = 0;
		for(int i = 0; i < n; i++)
		{
			c += b[i];
			mx = max(mx, c);
			if(c < 0)	c = 0;
		}
		ans += mx;
		cout << ans;;
	}
}