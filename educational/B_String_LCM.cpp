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
		string a, b;
		cin >> a >> b;
		int n = a.length();
		int m = b.length();
		int l = m * n / __gcd(m, n);
		string c = "", d = "";
		for(int i = 0; i < l/n; i++)	c += a;
		for(int i = 0; i < l/m; i++)	d += b;
		if(c == d)
		{
			cout << c << '\n';
		}
		else	cout << "-1\n";
	}
}