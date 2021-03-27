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
		int a, b;	cin >> a >> b;
		bitset<64> x(a), z(b);
		int p = 63 - __builtin_clzll(b);
		for(int i = p; i >= 0; i--)
		if(z[i] != x[i])
		{
			p = i;
			for(int j = i - 1; j >= 0; j--)
				z[j] = 1;
			break;
		}
		if(z.to_ullong() > b)	z[p] = 0;
		cout << z.to_ullong() << '\n';
	}
}