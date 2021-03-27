#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		int end = (m - 1) * (i + 1);
		if(end < n)
		ans += n - end;
	}
	cout << ans;
}