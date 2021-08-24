#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int R, C;	cin >> R >> C;
		int A[R][C];
		// vector<tuple<int, int, int>> rows, cols;
		vector<pair<int, int>> rows[R];
		vector<pair<int, int>> cols[C];
		for(int i = 0; i < R; i++)
		{
			int l = -1, r;
			for(int j = 0; j < C; j++)
			{
				cin >> A[i][j];
				if(A[i][j] == 1) {
					if(l == - 1) {
						l = j;
					}
					r = j;
				}
				else
				{
					if(l != -1)
					{
						// rows.emplace_back(i, l, r);
						rows[i].emplace_back(l, r);
						l = - 1;
					}
				}
			}
			if(l != -1)
			{
				rows[i].emplace_back(l, r);
				// rows.emplace_back(i, l, r);
				l = - 1;
			}
		}
		for(int j = 0; j < C; j++)
		{
			int l = -1, r;
			for(int i = 0; i < R; i++)
			{
				if(A[i][j] == 1) {
					if(l == - 1) {
						l = i;
					}
					r = i;
				}
				else
				{
					if(l != -1)
					{
						cols[j].emplace_back(l, r);
						// cols.emplace_back(j, l, r);
						l = - 1;
					}
				}
			}
			if(l != -1)
			{
				cols[j].emplace_back(l, r);
				// cols.emplace_back(j, l, r);
				l = - 1;
			}
		}
		// for(auto [a, b, c]: rows)
		// 	cout << a << ' ' << b << ' ' << c << '\n';
		// cout << '\n';
		// for(auto [a, b, c]: cols)
		// 	cout << a << ' ' << b << ' ' << c << '\n';
		int ans = 0;

		for(int i = 0; i < R; i++)
		{
			for(auto [l, r]: rows[i])
			for(int j = l; j <= r; j++) {
				int left = j - l + 1;
				int right = r - j + 1;

				int up = 0, down = 0;
				int beg = 0, end = cols[j].size() - 1;
				while(beg <= end)
				{
					int mid = beg + end >> 1;
					if(cols[j][mid].first > i)
						end = mid - 1;
					else if(cols[j][mid].second < i)
						beg = mid + 1;
					else
					{
						up = i - cols[j][mid].first + 1;
						down = cols[j][mid].second - i + 1;
						break;
					}
				}
				ans += max(0ll, min(right / 2, up) - 1);
				ans += max(0ll, min(right / 2, down) - 1);
				ans += max(0ll, min(left / 2, up) - 1);
				ans += max(0ll, min(left / 2, down) - 1);
			}
		}
		for(int i = 0; i < C; i++)
		{
			for(auto [l, r]: cols[i])
			for(int j = l; j <= r; j++) {
				int left = j - l + 1;
				int right = r - j + 1;

				int up = 0, down = 0;
				int beg = 0, end = rows[j].size() - 1;
				while(beg <= end)
				{
					int mid = beg + end >> 1;
					if(rows[j][mid].first > i)
						end = mid - 1;
					else if(rows[j][mid].second < i)
						beg = mid + 1;
					else
					{
						up = i - rows[j][mid].first + 1;
						down = rows[j][mid].second - i + 1;
						break;
					}
				}
				ans += max(0ll, min(right / 2, up) - 1);
				ans += max(0ll, min(right / 2, down) - 1);
				ans += max(0ll, min(left / 2, up) - 1);
				ans += max(0ll, min(left / 2, down) - 1);
			}
		}


		cout << "Case #" << _ << ": " << ans << '\n';
	}
}