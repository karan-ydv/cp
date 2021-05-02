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
		int n, m;		cin >> n >> m;
		string s[n];
		for(auto &x: s)	cin >> x;
		sort(s, s + n);
		// for(auto &x: s)	cout << x << '\n';
		int ans = m;
		for(int i = 1; i < n; i++)
		{
			int j;
			for(j = 0; j < m; j++)
			if(s[i][j] != s[i - 1][j])	break;
			ans += m - j;
		}
		cout << ans << '\n';
	}
}