#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		cout << "Case #" << _ << ": ";
		int n, k;	cin >> n >> k;
		string s;	cin >> s;
		s = "!" + s;
		int sum = 0;
		for(int i = 1; i <= n / 2; i++) {
			sum += (s[i] != s[n - i + 1]);
		}
		int ans = abs(sum - k);
		cout << ans << '\n';
	}
}