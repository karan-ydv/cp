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
		int n, k;	cin >> n >> k;
		k *= ((n + k - 1) / k);
		int ans = (k + n - 1) / n;
		cout << ans << '\n';
	}
}