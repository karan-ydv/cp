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
		int n, m, p;
		cin >> n >> m >> p;
		auto fun = [&]() {
			for(int i = 1; i <= sqrt(p); i++) {
				if(p % i == 0)
				{
					if(i <= n and p / i <= m)
						return cout << "YES\n", void();
					if(i <= m and p / i <= n)
						return cout << "YES\n", void();
				}
			}
			cout << "NO\n";
		};
		fun();
	}
}