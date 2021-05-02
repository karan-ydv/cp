#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n], b[n];
	for(int &x: a)	cin >> x;
	for(int &x: b)	cin >> x;
	int ans = 0;
	for(int i = 1; i <= 1000; i++)
	{
		bool flag = true;
		for(int j = 0; j < n; j++)
		if(!(a[j] <= i and i <= b[j]))
		{
			flag = false;
			break;
		}
		ans += flag;
	}
	cout << ans;
}