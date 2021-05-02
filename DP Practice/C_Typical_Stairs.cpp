#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int MAX = 1e5+5;
int dp[MAX];
bool M[MAX];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> x, M[x] = 1;
	
	dp[0] = 1;
	dp[1] = 1 - M[1];
	for(int i = 2; i <= n; i++)
		if(!M[i])	dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	
	cout << dp[n];
}