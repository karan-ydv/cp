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
		int a[n];	for(int &x: a)	cin >> x;
		int x = min_element(a, a + n) - a;
		int b[n], c = 0;

		for(int i = x; i < n; i++) {
			b[c++] = a[i];
		}
		for(int i = 0; i < x; i++) {
			b[c++] = a[i];
		}
		if(is_sorted(b, b + n))
		{
			cout << "YES\n";
			int moves = (x != 0);
			cout << moves << '\n';
		}
		else cout << "NO\n";
	}
}