#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int dp[10][N];

void filldp()
{
	for(int i = 0; i < 10; i++)
	for(int j = 1; j < 10; j++)
		dp[i][j] = j;
	for(int i = 10; i < N; i++)
	{
		for(int j = 0; j < 10; j++)
			dp[j][i] = dp[j][i - 1];
		string s = to_string(i);
		sort(s.begin(), s.end());
		int x = 0;
		for(int i = 1; i < s.length(); i++)
			x = max(s[i] - s[i - 1], x);
		for(int j = x; j < 10; j++)
			dp[j][i]++;
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("lucky.in", "r", stdin);
	filldp();
	int q;	cin >> q;
	while(q--)
	{
		int l, r, x;	cin >> l >> r >> x;
		x = min(x, 9);
		int res = dp[x][r] - dp[x][l - 1];
		cout << res << '\n';
	}
}