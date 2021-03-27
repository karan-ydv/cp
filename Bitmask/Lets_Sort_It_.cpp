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
		int n, x;	cin >> n >> x;
		vector<int> a(n), b;
		for(int &x: a)	cin >> x;
		b = a;
		for_each(b.begin(), b.end(), [&](int &val)
		{
			if(val > x)
				val = x;
		});
		int i;
		for(i = 1; i < n; i++) {
			if(b[i] < b[i - 1])	break;
		}
		int ans = -1;
		if(i == n)
		{

		}
	}
}