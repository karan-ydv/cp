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
		int flag = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int x;	cin >> x;
			flag |= 1LL << (x - 1);
			// cout << flag << ' ';
			if((flag & (flag + 1)) == 0)
				ans++;
		}
		cout << ans << '\n';
	}
}