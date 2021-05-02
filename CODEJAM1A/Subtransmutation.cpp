#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int ans;
		int n, a, b;	cin >> n >> a >> b;
		int u[50];	for(int i = 1; i <= n; i++)	cin >> u[i];
		bool vis[n + 1] = {0};
		for(int i = 1; i <= n; i++) {
			if(vis[i]) vis[i + a] = vis[i + b] = 1;
		}

		int c = 0;
		for(int i = 1; i <= n; i++)
		{
			if(u[i] != 0)	c++;
			else
			{
				if(c > a)	break;
				c = 0;
			}
		}
		if(c > a)
		{
			cout << "Case #" << _ << ": IMPOSSIBLE\n";
			continue;
		}
		auto check = [&](vector<int> &v)
		{
			for(int i = 1; i <= n; i++)
			if(v[i] < u[i])	return false;
			return true;
		};

		// for(int i = 1; i <= n; i ++)
		// {
		// 	for(int x = 1;)
		// 	for(int j = 1; j <= b; j++)
		// 	{
		// 		vector<int> v(n + 1);
		// 		for(int k = j; k <= n; k += b -a)
		// 		{

		// 		}
		// 	}
		// }
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}