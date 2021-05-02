#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mx = 3e4+5;
int dp[mx];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int coins[] = {1, 5, 10, 25, 50};
	dp[0] = 1;
	for(int c: coins)
	for(int i = c; i < mx; i++)
		dp[i] += dp[i - c];
	
	int n;
	while(cin >> n)
	{
		if(dp[n] == 1)	cout << "There is only 1 way to produce " << n << " cents change.\n";
		else			cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
	}
}