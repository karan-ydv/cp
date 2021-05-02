#include <bits/stdc++.h>
#define int long long
using namespace std;

#define f first
#define s second
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	pair<int, int> a[n];
	for(auto &[x, y]: a) {
		cin >> y >> x;
	}
	sort(a, a + n);
	int dp[n + 1];
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int j = 0;
		int beg = 0, end = i - 2;
		while(beg <= end)
		{
			int mid = beg + end >> 1;
			if(a[mid].f <= a[i - 1].s)
				beg = mid + 1, j = mid + 1;
			else
				end = mid - 1;
		}
		dp[i] = max(dp[i - 1], dp[j] + 1);
	}
	cout << dp[n];
}