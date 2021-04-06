#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
const int N = 2e5 + 1;
int dp[N][18];

void add(int &x, int val) {
	x += val;
	if(x >= mod)	x %= mod;
}

const char A[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;	int k;
	cin >> s >> k;
	int n = s.length();

	dp[1][1] = (find(A, A + 15, s[0]) - A) - 1;
	set<char> set = {s[0]};
	for(int i = 1; i < n; i++)
	{
		add(dp[i + 1][1], 15);
		for(auto j = A; j < find(A, A + 16, s[i]); j++)
		{
			if(set.find(*j) == set.end())
				add(dp[i + 1][set.size() + 1], 1);
			else
				add(dp[i + 1][set.size()], 1);
		}
		for(int j = 1; j <= 16; j++)
		{
			add(dp[i + 1][j], dp[i][j] * j);
			add(dp[i + 1][j + 1], dp[i][j] * (16 - j));
		}
		set.insert(s[i]);
	}
	int ans = dp[n][k];
	if(set.size() == k)	add(ans, 1);
	cout << ans;
}