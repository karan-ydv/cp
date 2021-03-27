#include <bits/stdc++.h>
#define int long long
using namespace std;

int fun(string &x, string &s) {
	int c = 0;
	int n = x.length();
	int m = s.length();
	for(int i = 0; i < x.length(); i++) {
		int j = i, k = 0;
		while(j < n and k < m) {
			if(s[k] == x[j])	j++;
			k++;
		}
		if(j == i)	c++;
		else
		{
			c += s.length() - (j - i) + 1;
			i = j - 1;
		}
	}
	cout << s << ' ' << x << ' ' << c << endl;
	return c;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string p, s; vector<string> v;
	getline(cin, p);
	getline(cin, s);
	s.erase(remove(s.begin(), s.end(), ' '), s.end());

	string t  = "";
	for(auto c: p)
	{
		if(c == ' ')
		{
			v.emplace_back(t);
			t = "";
		}
		else t += c;
	}
	if(t != "")
	v.emplace_back(t);

	int n = v.size();
	vector<int> cost(n, 1 << 30);
	vector<string> best(n);

	sort(s.begin(), s.end());
	do
	{
		for(int i = 0; i < n; i++)
		{
			int co = fun(v[i], s);
			if(co < cost[i])
			{
				cost[i] = co;
				best[i] = s;
			}
			if(co == cost[i])
			{
				best[i] = min(best[i], s);
			}
		}
    }
	while (next_permutation(s.begin(), s.end()));

	map<string, int> mp;
	for(int i = 0; i < n; i++) {
		mp[best[i]]++;
	}

	string ans; int mx = 0;
	for(auto [str, c]: mp) {
		if(c > mx) {
			mx = c;
			ans = str;
		}
	}
	cout << ans;
}