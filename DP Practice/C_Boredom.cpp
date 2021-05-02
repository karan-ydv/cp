#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+5;
int A[N], F[N], dp[N];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m = 0;	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;	cin >> x;
		m = max(m, x);
		F[x]++;
	}
	dp[1] = F[1];
	for(int i = 2; i <= m; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + i * F[i]);
	}
	cout << dp[m];
}