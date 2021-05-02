#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x;
		bool flag = false;
		for(int i = 0; i < n; i++)
		{
			int x = a[i];
			int s = sqrt(x);
			if(s * s != x)
			{
				flag = true;
				break;
			}
		}
		if(flag)
		cout << "YES\n";
		else
		cout << "NO\n";
	}
}