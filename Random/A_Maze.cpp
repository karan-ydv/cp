#include <bits/stdc++.h>
// #define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		string s(n, '8');
		for(int i = 0; i < n; i++)
		if(i != 1)
		{
			s[i] = char('0' + (8 + abs(i - 1)) % 10);
		}
		cout << s << '\n';
	}
}