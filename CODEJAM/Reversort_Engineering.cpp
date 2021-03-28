#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++)
	{
		cout << "Case #" << _ << ": ";
		int n, c;	cin >> n >> c;
		int x = n * (n + 1) / 2 - 1;
		if(c < n - 1 or c > x)
			cout << "IMPOSSIBLE";
		else
		{
			vector<int> ans(n), v(n, 1);
			iota(ans.begin(), ans.end(), 1);
			for(int i = 0; i < n - 1; i++)
			{
				int x = c - (n - 2 - i);
				if(x == 0) {
					break;
				}
				v[i] = min(n - i, x);
				c -= v[i];
			}
			for(int i = n - 1; i >= 0; i--)
				reverse(ans.begin() + i, ans.begin() + i + v[i]);
			for(int x: ans)	cout << x << ' ';
		}
		cout << endl;
	}
}