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
		int a, b, c;	cin >> a >> b >> c;
		string x = "1" + string(a - 1, '0');
		string y = string(b - (c - 1), '7') + string(c - 1, '0');
		cout << x << ' ' << y << '\n';
	}
}