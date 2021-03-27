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
		if(n & 1)
		{
			cout << "NO\n";
			continue;
		}
		if(s[0] != ')' and s[n - 1] != '(')
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}