#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	while(n != 1)
	{
		cout << n << ' ';
		if(n & 1)	n = n * 3 + 1;
		else		n >>= 1;
	}
	cout << n;
}