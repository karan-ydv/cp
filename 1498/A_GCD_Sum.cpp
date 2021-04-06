#include <bits/stdc++.h>
#define int long long
using namespace std;

int sum(int x) {
	int ret = 0;
	while(x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		for(int i = 0; i <= 1000; i++) {
			if(__gcd(n + i, sum(n + i)) > 1) {
				cout << n + i << '\n';
				break;
			}
		}
	}
}