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
		string s;
		int x, y;	cin >> x >> y >> s;

		int a = 0, b = 0;
		int L = count(s.begin(), s.end(), 'L');
		int R = count(s.begin(), s.end(), 'R');
		int U = count(s.begin(), s.end(), 'U');
		int D = count(s.begin(), s.end(), 'D');

		bool f1, f2;
		if(x < 0)	f1 = abs(x) <= L;
		else		f1 = abs(x) <= R;

		if(y < 0)	f2 = abs(y) <= D;
		else		f2 = abs(y) <= U;

		if(f1 and f2)	cout << "YES\n";
		else			cout << "NO\n";
	}
}