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
		int a[n];	for(int &x: a)	cin >> x;
		sort(a, a + n);
		int ans = a[0] * a[n - 1];
		int l = 0, r = n - 1;
		while(l <= r)
		{
			if(a[l] * a[r] != ans)
			{
				ans = - 1;
				break;
			}
			l++, r--;
		}
		if(ans != -1)
		{
			for(int i = 2; i <= sqrt(ans); i++) {
				if(ans % i == 0) {
					n -= 1 + (i * i != ans);
				}
			}
			if(n)	ans = -1;
		}
		cout << ans << '\n';
	}
}