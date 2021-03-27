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
		string s1, s2;	cin >> s1 >> s2;
		int n = s1.length(), m = s2.length();

		int ans = m + n;
		for(int i = 0; i < n; i++)
		for(int j = n - 1; j >= i; j--)
		for(int x = 0; x < m; x++)
		for(int y = m - 1; y >= x; y--)
		if(j - i == y - x)
		{
			bool flag = true;
			for(int a = i, b = x; a <= j; a++, b++)
			if(s1[a] != s2[b]) {
				flag = false;
				break;
			}
			if(flag)
			{
				ans = min(ans, m + n - (j - i + 1) - (y - x + 1));
			}
		}
		cout << ans << '\n';
	}
}