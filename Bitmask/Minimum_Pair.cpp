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
		int l, r;	cin >> l >> r;
		int a = l, b = l + 1;
		if(b > r or a + b > r)
			cout << "-1 -1\n";
		else
			cout << a << ' ' << b << '\n';
	}
}