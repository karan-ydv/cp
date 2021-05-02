#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(string s, int a, int b)
{
	int n = s.length();
	for(int i = 0; i < n / 2; i++)
	{
		int j = n - 1 - i;
		if(s[i] == '?')
		{
			if(s[j] != '?')
			{
				s[i] = s[j];
			}
		}
		else
		{
			if(s[j] == '?')
			{
				s[j] = s[i];
			}
			else if(s[j] != s[i])
			{
				cout << "-1\n";
				return;
			}
		}
	}
	int cnt0 = 0, cnt1 = 0;
	for(char c: s)
	{
		a -= (c == '0');
		b -= (c == '1');
		// cnt0 += (c == '0');
		// cnt1 += (c == '1');
	}
	for(int i = 0; i < n; i++)
	if(s[i] == '?')
	{
		int j = n - 1 - i;
		if(i == j)
		{
			if(a == 1)	s[i] = '0', a--;
			else if(b == 1)	s[i] = '1', b--;
		}
		else
		{
			if(a > 1)
			{
				s[i] = s[j] = '0';
				// cnt0 += 2 - (i == j);
				a -= 2;
			}
			else if(b > 1)
			{
				s[i] = s[j] = '1';
				// cnt1 += 2 - (i == j);
				b -= 2;
			}
		}
	}
	if(a == 0 and b == 0)
		cout << s << '\n';
	else
		cout << "-1\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		string s;
		int a, b;	cin >> a >> b >> s;
		solve(s, a, b);
	}
}