#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int R, C, ans = 0;	cin >> R >> C;
		int G[R][C];
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++)
				cin >> G[i][j];
		}
		vector<pair<int, int>> D = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		while(1)
		{
			int delta = 0;
			for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
			{
				int mx = G[i][j];
				for(auto [dx, dy]: D)
				{
					int a = i + dx, b = j + dy;
					if(a < 0 or a >= R)	continue;
					if(b < 0 or b >= C)	continue;
					mx = max(mx, G[a][b]);
				}
				if(mx - G[i][j] > 1) {
					delta += (mx - G[i][j] - 1);
					G[i][j] = mx - 1;
				}
				for(auto [dx, dy]: D)
				{
					int a = i + dx, b = j + dy;
					if(a < 0 or a >= R)	continue;
					if(b < 0 or b >= C)	continue;
					if(G[i][j] - G[a][b] > 1)
					{
						delta += G[i][j] - G[a][b] - 1;
						G[a][b] = G[i][j] - 1;
					}
				}
			}
			if(delta == 0)	break;
			ans += delta;
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}