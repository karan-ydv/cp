#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int sum = 0, x, a = 0, b = 0;
		for(int i = 0; i < n; i ++ )
		{
			cin >> x, sum += x;
			a += x == 1;
			b += x == 2;
		}
		if(sum & 1)	cout << "NO\n";
		else
		{
			if(b & 1 and a == 0)	cout << "NO\n";
			else					cout << "YES\n";
		}
	}
}