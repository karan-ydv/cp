#include <bits/stdc++.h>
#define int long long
using namespace std;

int sumofsquares(int n) {
	int ans = n * (n + 1) * (2 * n + 1) / 6;
	return ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	int N = 1e5;
	int a[N];
	a[0] = 0;
	for(int i = 1; i <= N; i++) {
		a[i] = a[i - 1] + i;
	}
	while(t--)
	{
		int n;	cin >> n;
		int i = lower_bound(a, a + N, n) - a;
		int ans = sumofsquares(i - 1) + i * (n - a[i - 1]);
		cout << ans << '\n';
	}
}