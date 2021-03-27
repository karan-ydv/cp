#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	auto fun = [](int x, int d) {
		while(x)
		{
			if(x % d == 0)	return true;
			x -= x % d;
		}
		return false;
	};
	while(t--)
	{
		int n, d;	cin >> n >> d;
		while(n--)
		{
			int x;	cin >> x;
			if(fun(x, d))	cout << "YES\n";
			else			cout << "NO\n";
		}
		
	}
}