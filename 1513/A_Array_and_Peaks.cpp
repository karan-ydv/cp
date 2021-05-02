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
		int n, k;	cin >> n >> k;
		if(k > (n - 1) / 2)
		{
			cout << "-1\n";
			continue;
		}
		vector<int> v;
		v.emplace_back(1);
		int x = 2;
		while(k--)
		{
			v.emplace_back(x + 1);
			v.emplace_back(x);
			x += 2;
		}
		for(; x <= n; x++)	v.emplace_back(x);
		for(int x: v)	cout << x << ' ';
		cout << '\n';
	}
}