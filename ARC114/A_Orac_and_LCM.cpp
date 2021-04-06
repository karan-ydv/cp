#include <bits/stdc++.h>
#define int long long
using namespace std;

int lcm(int a, int b) {return a * b / __gcd(a, b);}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	// lcm and gcd distribute over each other:
	// gcd(lcm(a1, a2), lcm(a1, a3) ... lcm(a1, an)) = lcm(a1, gcd(a2, a3 ... an)) and
	// lcm(gcd(a1, a2), gcd(a1, a3) ... gcd(a1, an)) = gcd(a1, lcm(a2, a3 ... an))
	// ans = gcd(lcm(a1, gcd(a2 .. an)), lcm(a2, gcd(a3 .. an)) ....) or
	// ans = gcd(lcm(gcd(a1 .. a1), a2), lcm(gcd(a1 .. a2), a3) ...)
	int ans = 0, pref = 0;
	for(int i = 0; i < n; i++)
	{
		int x;	cin >> x;
		ans = __gcd(ans, lcm(pref, x));
		pref = __gcd(x, pref);	// gcd of prefix
	}
	cout << ans;
}