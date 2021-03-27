#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int dp[1 << N][2][N * N + 1];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n;
	char color[n];
	int r[n], b[n];

	m = 1 << n;
	int red = 0, blu = 0;
	for(int i = 0; i < n; i++) {
		cin >> color[i] >> r[i] >> b[i];

		red += max(0, r[i] - n);
		blu += max(0, b[i] - n);

		r[i] = min(r[i], n);
		b[i] = min(b[i], n);

		// cout << color[i] << ' ' << r[i] << ' ' << b[i] << '\n';

	}

	fill_n(dp[0][0], sizeof(dp) / sizeof(int), 1 << 30);

	// R[i] = no. of red cards in ith state
	int R[m] = {0}, B[m] = {0};
	for(int i = 0; i < m; i++)
	for(int x = 1, j = 0; x < m;  x <<= 1, j++) {
		if(i & x) {
			R[i] += (color[j]  == 'R');
			B[i] += (color[j]  == 'B');
		}
	}
	// cout << red << ' ' << blu << '\n';
	int ans = max(red, blu) + n;
	int mn = min(red, blu);
	red -= mn, blu -= mn;
	// cout << red << ' ' << blu << '\n';
	blu = min(blu, n * n);
	red = min(red, n * n);

	// if(red == 0)	dp[0][0][blu] = 0;
	// if(blu == 0)	dp[0][1][red] = 0;

	for(int i = 0; i <= red; i++)
		dp[0][1][i] = 0;
	for(int i = 0; i <= blu; i++)
		dp[0][1][i] = 0;
	for(int i = 0; i < m - 1; i++)
	{
		for(bool col: {0, 1})
		for(int k = 0; k <= n * n; k++)
		if(dp[i][col][k] != 1 << 30)
		for(int j = 0, x = 1; x < m; j++, x <<= 1) if(!(i & x))
		{
			int hvred = col ? k : 0;
			int hvblu = col ? 0 : k;
			int needred = max(r[j] - R[i], 0);
			int needblu = max(b[j] - B[i], 0);
			
			int gettokens = max(needred - hvred, needblu - hvblu);
			int leftred = min(hvred + gettokens - needred, n * n);
			int leftblu = min(hvblu + gettokens - needblu, n * n);
			if(leftred == 0)
			dp[i | x][0][leftblu] = min(dp[i | x][0][leftblu], dp[i][col][k] + gettokens);
			if(leftblu == 0)
			dp[i | x][1][leftred] = min(dp[i | x][1][leftred], dp[i][col][k] + gettokens);
		}
	}
	m--;
	int x = 1 << 30;
	for(int i = 0; i <= n * n; i++)
		x = min(x, min(dp[m][0][i], dp[m][1][i]));
	// cout << x << '\n';
	ans += x;
	cout << ans;
}