#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		string s;
		int ans = 0, x, y, n;
		cin >> x >> y >> s;

		n = s.length();
		s = "x" + s + "x";

		vector<tuple<char, int, char>> v;
		for(int i = 0; i <= n; i++)
		{
			if(s[i + 1] == '?')
			{
				int j;
				for(j = i + 2; j <= n + 1; j++) {
					if(s[j] != '?')	break;
				}
				v.emplace_back(s[i], j - i - 1, s[j]);
				i = j - 1;
			}
			else
			{
				string str = "";
				str += s[i];
				str += s[i + 1];
				if(str == "CJ")	ans += x;
				if(str == "JC")	ans += y;
			}
		}

		if(x >= 0 and y >= 0)
		{
			for(auto [a, b, c]: v)
			{
				int cstC = 0, cstJ = 0;
				if(a == 'C')	cstJ += x;
				if(a == 'J')	cstC += y;
				if(c == 'C')	cstJ += y;
				if(c == 'J')	cstC += x;
				ans += min(cstC, cstJ);
			}
		}
		else
		{
			for(auto [a, b, c]: v)
			{
				int cstC = 0, cstJ = 0;
				if(a == 'C')	cstJ += x;
				if(a == 'J')	cstC += y;
				if(c == 'C')	cstJ += y;
				if(c == 'J')	cstC += x;

				int cj, jc;
				cj = (b + 1) / 2;
				ans += min(cstC, cstJ);
			}
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}