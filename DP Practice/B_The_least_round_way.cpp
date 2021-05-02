#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3+5;
int dp[N][N][2], A[N][N];
int F[N][N][2];

int f(int x, int k)
{
	int c = 0;
	while(x % k == 0)
	{
		c++;
		x /= k;
	}
	return c;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	vector<pair<int, int>> zero;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		cin >> A[i][j];
		if(A[i][j] == 0)
		{
			if(zero.empty())
			zero.emplace_back(i, j);
			A[i][j] = 10;
		}
		F[i][j][0] = f(A[i][j], 2);
		F[i][j][1] = f(A[i][j], 5);
	}
	
	for(int i = 1; i <= n; i++)	
		dp[0][i][0] =  dp[0][i][1] = 1 << 30,
		dp[i][0][0] =  dp[i][0][1] = 1 << 30;

	dp[0][1][0] = dp[1][0][0] = 0;
	dp[0][1][1] = dp[1][0][1] = 0;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
		dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + F[i][j][0],
		dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j - 1][1]) + F[i][j][1];
	
	int x = dp[n][n][1] < dp[n][n][0];
	if(dp[n][n][x] > 1 and !zero.empty())
	{
		auto [x, y] = zero[0];
		string ans = string(x - 1, 'D') + string(y - 1, 'R');
		ans += string(n - x, 'D') + string(n - y, 'R');
		return cout << "1\n" << ans, 0;
	}
	string ans = "";
	int i = n, j = n;
	while(!(i == 1 and j == 1))
	{
		if(dp[i][j][x] == dp[i - 1][j][x] + F[i][j][x])
			ans += 'D', i--;
		else if(dp[i][j][x] == dp[i][j - 1][x] + F[i][j][x])
			ans += 'R', j--;
	}
	reverse(ans.begin(), ans.end());
	cout << dp[n][n][x] << '\n';
	cout << ans;
}