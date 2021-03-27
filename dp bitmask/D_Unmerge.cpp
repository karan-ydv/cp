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
		n <<= 1;
		int a[n];	for(int &x: a)	cin >> x;
		vector<int> v;
		vector<bool> vis(n + 1);
		int c = 0;
		for(int i = n, j = n - 1; j >= 0; j--)
		{
			vis[a[j]] = true;
			c++;
			if(a[j] == i)
			{
				v.emplace_back(c);
				c = 0;
				while(vis[i])	i--;
			}
		}
		v.emplace_back(c);
		bitset<2001> s;
		s[0] = 1;
		for(int x: v)	s |= s << x;
		if(s[n / 2])	cout << "YES\n";
		else			cout << "NO\n";
	}
}