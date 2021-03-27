#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		string s, t;
		cin >> s >> t;
		int L = 0, R;
		int n = s.length();
		int m = t.length();
		for(R = 0; R < n; R++) {
			while(L < m and t[L] != s[R]) L++;
			if(L == m)	break;
		}
		if(R == s.length())	cout << "YES\n";
		else				cout << "NO\n";
	}
}