#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int cmp(string a, string b)
{
	int m = a.length(), n = b.length();
	for(int i = 0; i < min(m, n); i++)
	{
		if(a[i] != b[i])	return a[i] - b[i];
	}
	return 0;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int n;	cin >> n;
		string a[n];	for(auto &x: a)	cin >> x;
		int ans = 0;
		for(int i = 1; i < n; i++)	if(a[i] <= a[i - 1])
		{
			string s1 = to_string(a[i - 1]);
			string s2 = to_string(a[i]);

			int k = s1.length() - s2.length();
			if(k == 0)
			{
				ans ++;
				a[i] *= 10;
				continue;
			}
			if(cmp(s2 + string(k, '0'), s1) > 0)
			{
				ans += k;
				a[i] *= pow(10, k);
			}
			int p = a[i - 1].length();
			int q = a[i].length();
			if(stoi(a[i]) > stoi(a[i - 1]))	continue;
			int x = cmp(a[i - 1], a[i]);
			if(x == 0)
			{
				int y = stoi(a[i - 1]) + 1;
				string s = to_string(y);
				if(cmp(s, a[i]) == 0)
				{
					a[i] = s;
					ans += s.length() - a[i].length();
				}
				else
				{
					ans += p + 1 - q;
					a[i] += string(p + q - 1, '0');
				}
			}
			else
			{
				a[i] += string(p - q,'0');
				ans += p - q;
				if(x > 0)
				{
					ans++;
					a[i] += '0';
				}
			}
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}