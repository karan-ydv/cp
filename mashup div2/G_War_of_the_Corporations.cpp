#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	int ans = 0;
	for(int i = 0; i + m <= n; i++) {
		if(s[i] == t[0])
		{
			int j;
			for(j = 0; j < m; j++) {
				if(s[i + j] != t[j])	break;
			}
			if(j != m)	continue;
			i += m - 1;
			s[i] = '#';
			ans ++;
		}
	}
	// cout << s <<  '\n';
	cout << ans;
}