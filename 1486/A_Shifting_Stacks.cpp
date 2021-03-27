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
		int n;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x;
		int c = 0;
		bool flag = true;
		for(int i = 0; i < n; i++) {
			if(a[i] > i)
			{
				c += a[i] - i;
			}
			else if(a[i] < i)
			{
				if(c < i - a[i]) {
					flag = false;
					break;
				}
				c -= i - a[i];
				a[i] = i;
			}
		}
		if(flag)	cout << "YES\n";
		else		cout << "NO\n";
	}
}