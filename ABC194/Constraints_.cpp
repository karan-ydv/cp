#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	int a[n];	for(int &x: a)	cin >> x;
	if(k == 1)	return cout << a[0], 0;
	k = max(k, n);
	int ans = *max_element(a, a + k - 1);
	cout << ans;
}