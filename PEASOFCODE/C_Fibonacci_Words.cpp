#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;	cin >> s;
	bool flag = true;
	for(char c: s)	cout << c - 'A' + 1 << " "; cout << '\n';
	for(int i = 2; i < s.length(); i++)
	{
		if(s[i] - 'A' != s[i - 1] - 'A' + s[i - 2] - 'A')
		{
			flag = false;
			break;
		}
	}
	if(flag)	cout << "YES\n";
	else		cout << "NO\n";
}