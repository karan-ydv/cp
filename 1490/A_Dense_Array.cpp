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
		int ans = 0;
		for(int i = 1; i < n; i++) {
			if(max(a[i], a[i - 1]) > 2 * min(a[i], a[i - 1])) {
				int x = min(a[i], a[i - 1]);
				int y = max(a[i], a[i - 1]);
				while (y > 2 * x)
				{
					x <<= 1;
					ans ++;
				}
				
				// ans++;
			}
		}
		cout << ans << '\n';
	}
}