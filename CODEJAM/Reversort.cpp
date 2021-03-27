#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int ans = 0;
		int n;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x;
		for(int i = 1; i < n; i++)
		{
			int j;
			for(j = i - 1; j < n; j++) {
				if(a[j] == i)	break;
			}
			reverse(a + i - 1, a + j + 1);
			ans += j - i + 2;
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}