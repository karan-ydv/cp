#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	string s = "";
	for(char c = 'a'; c < 'a' + k; c++)
	{
		s += c;
		for(char d = c + 1; d < 'a' + k; d++)
			s += c, s += d;
	}
	// cout << s;
	while(s.length() < n)	s += s;
	cout << s.substr(0, n);
}