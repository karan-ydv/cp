#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, k;	cin >> n >> k;
		vector<vector<bool>> A(n, vector<bool>(n));
		queue<pair<int, int>> q;
		q.push({0, 0});
		for(int i = 1; i < n; i++) {
			q.push({0, i});
			q.push({n - i, 0});
		}
		while(k)
		{
			auto [x, y] = q.front(); q.pop();
			while(x < n and y < n and k > 0)
			{
				A[x++][y++] = 1;
				k--;
			}
		}
		int Rmx = 0, Rmn = 1 << 30, Cmx = 0, Cmn = 1 << 30;
		for(int i = 0; i < n; i++)
		{
			int r = 0, c = 0;
			for(int j = 0; j < n; j++)
				r += A[i][j], c += A[j][i];
			Rmx = max(Rmx, r);
			Rmn = min(Rmn, r);
			Cmx = max(Cmx, c);
			Cmn = min(Cmn, c);
		}
		int ans = (Rmx - Rmn) * (Rmx - Rmn) + (Cmx - Cmn) * (Cmx - Cmn);
		cout << ans << '\n';
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)	cout << A[i][j];
			cout << '\n';
		}
	}
}