#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int f[32], g[32];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	f[0] = 1;
	g[1] = 1;
	for(int i = 2; i <= 30; i++)
	{
		f[i] = f[i - 2] + 2 * g[i - 1];
		g[i] = f[i - 1] + g[i - 2];
	}
	int x;
	while(cin >> x, x != -1)
	{
		cout << f[x] << '\n';
	}
}