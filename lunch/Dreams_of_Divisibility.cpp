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
		int a[n];	for(int& x: a)	cin >> x, x = __gcd(x, k);
		if(all_of(a, a + n, [](int x){return x == 1;})) {
			cout << "NO\n";
		}
		else	cout << "YES\n";
	}
}