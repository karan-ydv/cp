#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;	cin >> n >> x;
	int p[n];	for(int &w: p)	cin >> w;
	sort(p, p + n);
	int l = 0, r = n - 1, ans = 0;
	while(l < r)
	{
		if(p[l] + p[r] <= x) {
			ans ++;
			l++, r--;
		}
		else {
			ans++, r--;
		}
	}
	if(l == r)	ans ++;
	cout << ans;
}