#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+5;
bool dp[N][7];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; string s, x;
	cin >> n >> s >> x;
	x = "!" + x;	s = "!" + s;
	dp[n][0] = true;
	for(int i = n; i > 0; i--)
	{
		for(int j = 0; j < 7; j++)
		{
			bool p = dp[i][(j * 10) % 7];
			bool q = dp[i][(j * 10 + s[i] - '0') % 7];
			dp[i - 1][j] = x[i] == 'A' ? p & q : p | q;
		}
	}
	cout << '\n';
	if(dp[0][0])	cout << "Takahashi";
	else			cout << "Aoki";
}