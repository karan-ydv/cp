#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
const int M = 11, N = 1e3+3;
int a[M][N], b[M][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		a[1][i] = b[1][i] = 1;

	for(int i = 2; i <= m; i++) {
		for(int x = 1; x <= n; x++) {
			for(int y = 1; y <= x; y++)
			{
				a[i][x] += a[i - 1][y];
				if(a[i][x] >= mod)
					a[i][x] -= mod;
			}
			for(int y = x; y <= n; y++)
			{
				b[i][x] += b[i - 1][y];
				if(b[i][x] >= mod)
					b[i][x] -= mod;
			}
		}
	}
	
	int ans = 0;
	for(int x = 1; x <= n; x++)
	for(int y = x; y <= n; y++)
	{
		ans += a[m][x] * b[m][y] % mod;
		if(ans > mod)	ans -= mod;
	}

	cout << ans;
}