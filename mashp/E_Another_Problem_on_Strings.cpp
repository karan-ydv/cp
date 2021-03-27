#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int k;	cin	>> k >> s;
	int n = s.length();
	if(k == 0)
	{
		int c = 0, ans = 0;
		s += "1";
		for(int i = 0; i <= n; i++) {
			if(s[i] == '1') {
				ans += c * (c + 1) / 2;
				c = 0;
			}
			else c++;
		}
		return cout << ans, 0;
	}

	int ans = 0, c = 0, d = 0;
	int L = -1;
	for(int R = 0; R < n; R++) {
		if(s[R] == '1') {
			if(c < k)	c++;
			if(c == k)
			{
				d = 1;
				while(s[++L] != '1') {
					d++;
				}
				c--;
			}
		}
		ans += d;
	}
	cout << ans;
}