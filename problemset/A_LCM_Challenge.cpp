#include <bits/stdc++.h>
#define int long long
using namespace std;

int lcm(int a, int b) { return a * b / __gcd(a, b); }
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	if(n <= 2)	return cout << n, 0;
	if(n == 3)	return cout << "6", 0;
	if(n & 1)	return cout << n * (n - 1) * (n - 2), 0;
	int ans = (n - 1) * (n - 2) * (n - 3);
	for(int i = max(n - 50, 1LL); i <= n; i++)
	for(int j = max(n - 50, 1LL); j <= n; j++)
	for(int k = max(n - 50, 1LL); k <= n; k++)
		ans = max(ans, lcm(lcm(i, j), k));
	cout << ans;
}