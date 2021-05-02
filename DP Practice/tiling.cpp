#include <bits/stdc++.h>
using namespace std;

const int N = 3;
int dp[50][1 << N];
vector<int> allowed[1 << N];
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = 3, m = 32;
	int p = 1 << n;
 
	for(int i = 0; i < p; i++)
	{
		bitset<N> b(i);
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
		if(dp[0][i])	cout << b.to_string() << '\n';
	}
 
	for(int i = 0; i < p; i++)
	{
		bitset<N> x(i);
		cout << x.to_string() << ": ";
		for(int j = 0; j < p; j++)
		if(!(i & j))
		{
			bitset<N> y(j);
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
			{
				allowed[i].emplace_back(j);
				cout << y.to_string() << ' ';
			}
		}
		cout << '\n';
	}
 
	for(int i = 1; i < m; i++)
	for(int j = 0; j < p; j++)
	for(int k: allowed[j])
	{
		dp[i][j] += dp[i - 1][k];
	}
	
	int x;
	while(cin >> x, x != -1)
	{
		cout << dp[x - 1][0] << '\n';
	}
}