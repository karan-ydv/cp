#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	vector<int> A[n + 2];
	for(int i = 0; i < n; i++)
	{
		int x, c;	cin >> x >> c;
		A[c].emplace_back(x);
	}

	A[n + 1].emplace_back(0);
	int	dp[n + 2][2], cords[n + 2][2];
	dp[0][0] = dp[0][1] = 0;
	cords[0][0] = cords[0][1] = 0;

	for(int i = 1; i <= n + 1; i++)
	if(!A[i].empty())
	{
		int max = *max_element(A[i].begin(), A[i].end());
		int min = *min_element(A[i].begin(), A[i].end());
		cords[i][0] = max;
		cords[i][1] = min;
		dp[i][0] = std::min(dp[i - 1][0] + abs(cords[i - 1][0] - min),
							dp[i - 1][1] + abs(cords[i - 1][1] - min)) + max - min;
		dp[i][1] = std::min(dp[i - 1][0] + abs(cords[i - 1][0] - max),
							dp[i - 1][1] + abs(cords[i - 1][1] - max)) + max - min;
	}
	else
	{
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][1];
		cords[i][0] = cords[i - 1][0];
		cords[i][1] = cords[i - 1][1];
	}
	
	int ans = min(dp[n + 1][0], dp[n + 1][1]);
	cout << ans;
}