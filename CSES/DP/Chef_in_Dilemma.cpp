#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;	cin >> s;
	int n = s.length();
	int mn = 1 << 30;
	string ans;
	for(char i = 'a'; i <= 'z'; i++)
	for(char j = 'a'; j <= 'z'; j++)
	for(char k = 'a'; k <= 'z'; k++)
	{
		int cnt = 0, p = 0;
		string str;
		while(p < n)
		{
			while(p < n and s[p] != i)	p++, cnt++;
			if(p < n)	str += s[p];
			p++;
			while(p < n and s[p] != j)	p++, cnt++;
			if(p < n)	str += s[p];
			p++;
			while(p < n and s[p] != k)	p++, cnt++;
			if(p < n)	str += s[p];
			p++;
		}
		if(cnt < mn)	mn = cnt, ans = str;
		if(cnt == mn)	ans = min(ans, str);
	}
	cout << mn << ' ' << ans;
}