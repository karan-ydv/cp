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
		int w, h, n;	cin >> w >> h >> n;
		int a = 1 << __builtin_ctzll(w);
		int b = 1 << __builtin_ctzll(h);
		if(a * b >= n)	cout << "YES\n";
		else			cout << "NO\n";
	}
}