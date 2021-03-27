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
		int n, d;	cin >> n >> d;
		int a[n];	for(int &x: a)	cin >> x;
		if(all_of(a, a + n, [&](int x){return x <= d;}))
		{
			cout << "YES\n";
			continue;
		}
		bool flag = false;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		if(i != j)
		{
			if(a[i] + a[j] <= d)
			{
				flag = true;
				goto doom;
			}
		}
		doom:
		flag ? cout << "YES\n" : cout << "NO\n";
	}
}