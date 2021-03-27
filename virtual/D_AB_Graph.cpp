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
		int n, m;	cin >> n >> m;
		string s[n];
		for(auto &x: s)	cin >> x;

		if(n & 1)
		{
			cout << "YES\n";
			int x = 1;
			for(int i = 0; i <= m; i++) {
				cout << x << ' ';
				x = 3 - x;
			}
			cout << '\n';
		}
		else
		{
			int a = 0, b = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++)
				if(j != i)
				{
					if(s[i][j] == s[j][i])
					{
						a = i + 1, b = j + 1;
						goto end;
					}
				}
			}
			end:
			if(a and b)
			{
				cout << "YES\n";
				int x = a;
				for(int i = 0; i <= m; i++) {
					cout << x << ' ';
					x = a + b - x;
				}
				cout << '\n';
			}
			else
				cout << "NO\n";
		}
	}
}