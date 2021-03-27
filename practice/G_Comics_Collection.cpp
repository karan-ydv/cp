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
		int ans = 0;
		int a = (n / 5);
		int b = (n / 3 - n / 15);
		int c = (n / 2 - n / 6 - n / 10 + n / 30);
		ans += 5 * a;
		ans += 3 * b;
		ans += 2 * c;
		ans += n - (a + b + c);
		cout << ans << '\n';
	}
}