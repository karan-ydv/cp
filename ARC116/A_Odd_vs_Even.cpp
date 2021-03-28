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
		int c = 0;
		while(n % 2 == 0)	c++, n >>= 1;
		if(c == 0)		cout << "Odd\n";
		else if(c == 1)	cout << "Same\n";
		else			cout << "Even\n";
	}
}