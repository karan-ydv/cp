#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int dp[1 << N][2][16];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n;
	char color[n];
	int r[n], b[n];

	m = 1 << n;
	int red = 0, blue = 0;
	for(int i = 0; i < n; i++) {
		cin >> color[i] >> r[i] >> b[i];

		red += max(0, r[i] - n);
		blue += max(0, b[i] - n);

		r[i] = min(r[i], n);
		b[i] = min(b[i], n);
	}
	for(int i = 0; i < n; i++)
		if(red < blue)	dp[0][1][i] = blue - red;
		else			dp[0][0][i] = red - blue;
	
	int R[m], B[m];
	for(int i = 0; i < m; i++)
	for(int x = 1, j = 0; x < m;  x <<= 1, j++) {
		if(i & x) {
			R[i] += (color[j]  == 'R');
			B[i] += (color[j]  == 'B');
		}
	}

	int ans = max(red, blue);
	for(int i = 0; i < m; i++) {
		for(int j = 0, x = 1; j < n; j++, x <<= 1) {
			if(!(i & x)) {
				dp[i | x][]
			}
		}
	}

	cout << ans;
}