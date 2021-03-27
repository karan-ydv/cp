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
		string s;	cin >> s;
		int n = s.length();
		for(int i = 0; i < n; i++)
		{
			if(i&1)
			{
				if(s[i] != 'z')
					s[i] = 'z';
				else
					s[i] = 'y';
			}
			else
			{
				if(s[i] != 'a')
					s[i] = 'a';
				else
					s[i] = 'b';
			}
		}
		cout << s << '\n';
	}
}