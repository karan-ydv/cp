#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	while(getline(cin, s1))
	{
		getline(cin, s2);
		int n = s1.length();
		int m = s2.length();

		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
		cout << dp[n][m] << '\n';
	}
}