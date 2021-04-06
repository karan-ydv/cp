#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
const int N = 1 << 20;
int dp[N];
// dp[i] = number of coprime sets that only have multiples of all primes of bitset i
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;	cin >> a >> b;
	dp[0] = 1;
	for(int x = a; x <= b; x++)
	{
		int mask = 0;	// all primes that divide x
		for(int j = 0, k = 1; j < 20; j++, k <<= 1)
			if(x % prime[j] == 0)	mask |= k;
		for(int i = 0; i < N; i++)
			if((mask & i) == 0)	dp[i | mask] += dp[i];
	}
	int ans = accumulate(dp, dp + N, 0ll);
	cout << ans;
}