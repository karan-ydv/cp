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
		map<int, int> map;
		int a[n];
		for(int &x: a)	cin >> x, map[x++];
		
		int val;
		for(auto [x, f]: map)
		if(f == 1)
		{
			val = x;
		}
		int ans = find(a, a + n, val) - a; ans++;
		cout << ans << '\n';
	}
}