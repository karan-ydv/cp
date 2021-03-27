#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> A = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int n;	cin >> n;
	vector<int> v(n);	for(int &a: v)	cin >> a;

	int ans = 1e18;
	for(int i = 0; i < 32768; i++) {
		int j = 0, x = i, p = 1;
		while(x) {
			if(x & 1){
				p *= A[j];
			}
			j++;
			x >>= 1;
		}
		bool noncoprime = true;
		for(int a: v)
		if(__gcd(a, p) == 1)
		{
			noncoprime = false;
			break;
		}
		if(noncoprime) ans = min(ans, p);
	}
	cout << ans;
}