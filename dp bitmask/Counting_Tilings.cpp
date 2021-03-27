#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int N = 10;
int dp[1000][1 << N];
vector<int> allowed[1 << N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int p = 1 << n;

	for(int i = 0; i < p; i++)
	{
		bitset<10> b(i);
		int c = 0;
		for(int j = 0; j < n; j++)
		{
			if(b[j])
			{
				if(c & 1)	break;
				c = 0;
			}
			else	c++;
		}
		dp[0][i] = (!(c & 1));
	}

	for(int i = 0; i < p; i++)
	for(int j = 0; j < p; j++)
	if(!(i & j))
	{
		bitset<10> x(i), y(j);
		int c = 0;
		for(int k = 0; k < n; k++) {
			if(x[k] or y[k])
			{
				if(c & 1)	break;
				c = 0;
			}
			else	c++;
		}
		if(!(c & 1))
		allowed[i].emplace_back(j);
	}

	for(int i = 1; i < m; i++)
	for(int j = 0; j < p; j++)
	for(int k: allowed[j])
	{
		dp[i][j] += dp[i - 1][k];
		if(dp[i][j] >= mod)
			dp[i][j] -= mod;
	}
	
	cout << dp[m - 1][0];
}