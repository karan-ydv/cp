#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p = 15, x;
	for(int i = 2; i <= p; i++)
	{
		int x = i;
		for(int j = 0; j < p - i; j++) {
			x *= i;
		}
		cout << x << '\n';
	}
}