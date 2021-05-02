#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e6+6;
int dp[N];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n];	for(int &x: a)	cin >> x, dp[x] = 1;

	for(int x: a)
	{
		for(int y = x + x; y <= a[n - 1]; y += x)
		if(dp[y])	dp[y] = max(dp[y], dp[x] + 1);
	}
	
	cout << *max_element(dp, dp + a[n - 1] + 1);
}