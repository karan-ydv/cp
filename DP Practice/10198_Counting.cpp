#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e3+5;
int dp[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	// dp[1] = 2;
	// dp[2] = 5;
	for(int i = 1; i < N; i++) {
		dp[i] += 2 * dp[i - 1];
		if(i > 1)
		dp[i] += dp[i - 2];
		if(i > 2)
		dp[i] += dp[i - 3];
	}
	int n;
	while(cin >> n)
	{
		cout << dp[n] << '\n';
	}
}