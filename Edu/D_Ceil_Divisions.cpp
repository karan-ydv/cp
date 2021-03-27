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
		vector<pair<int, int>> v;
		for(int k = 1; k < 10; k++){
			if(k + ceil(log2(n) / k) <= 9)
			{
				int x = 1 << k;
				for(int i = n - 1; i > 2; i--)
				if(i != x)
				{
					v.push_back({i, n});
				}
				int p = n;
				while(n > 1)
				{
					v.push_back({p, x});
					n = ceil(1.0 * n / x);
				}
				p = x;
				if(x != 2)
				while(x > 1)
				{
					v.push_back({p, 2});
					x = ceil(1.0 * x / 2);
				}
				break;
			}
		}
		cout << v.size() << '\n';
		for(auto [x, y]: v)	cout << x << ' ' << y << '\n';
	}
}