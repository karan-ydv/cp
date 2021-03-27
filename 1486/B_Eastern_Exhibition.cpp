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
		int a[n], b[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		
		sort(a, a + n);
		sort(b, b + n);

		int ans;
		if(n & 1) {
			ans = 1;
		}
		else {
			ans = (a[n / 2] - a[n / 2 - 1] + 1) * (b[n / 2] - b[n / 2 - 1] + 1);
		}
		cout << ans << '\n';
	}
}