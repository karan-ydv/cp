#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#define f first
#define s second

const int N = 19;
int dp[1 << N];
vector<pair<int, int>> YZ[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;	cin >> x >> y >> z;
		YZ[x].emplace_back(y, z);
	}
	dp[0] = 1;
	for(int i = 0; i < (1 << n); i++)
	{
		bitset<20> b(i);
		int f[20] = {0};
		for(int k = 0; k < n; k++)
			f[k + 1] = f[k] + b[k];
		
		for(int j = 0, x = 1; j < n; j++, x <<= 1) if(!b[j])
		{
			bool flag = true;
			for(auto [y, z]: YZ[b.count() + 1])
			{
				int c = (j + 1 <= y) + f[y];
				if(c > z)
				{
					flag = false;
					break;
				}
			}
			if(flag)	dp[i | x] += dp[i];
		}
	}
	cout << dp[(1 << n) - 1];
}