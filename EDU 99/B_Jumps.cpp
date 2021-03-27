#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int dp[N + 1], c = 2, d = 1;
	dp[1] = 1;
	for(int i = 2; i <= N; i++) {
		if(d == (c - 1))
			dp[i] = c + 1;
		else
			dp[i] = c;
		if(d == c) {
			c++;
			d = 0;
		}
		d++;
	}
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		cout << dp[n] << '\n';
	}
}