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
		int b[3] = {0};
		int a[n];	for(int &x: a)	cin >> x, x %= 3, b[x]++;
		int ans = 0;
		if(b[0] > n / 3)
		{
			ans += b[0] - n / 3;
			b[1] += b[0] - n / 3;
			if(b[1] > n / 3)
			{
				ans += b[1] - n / 3;
				b[2] += b[1] - n / 3;
			}
			if(b[2] > n / 3)
			{
				ans += 2 * (b[2] - n / 3);
			}
		}
		else if(b[1] > n / 3)
		{
			ans += b[1] - n / 3;
			b[2] += b[1] - n / 3;
			if(b[2] > n / 3)
			{
				ans += b[2] - n / 3;
				b[0] += b[2] - n / 3;
			}
		}
		else if(b[2] > n / 3)
		{
			ans += b[2] - n / 3;
			b[0] += b[2] - n / 3;
			if(b[0] > n / 3)
			{
				ans += b[0] - n / 3;
			}
		}
		cout << ans << '\n';
	}
}