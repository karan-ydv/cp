#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;	cin >> n;
	if(n == 2 or n == 3)
		return cout << "NO SOLUTION", 0;
	if(n == 4)	
		return cout << "3 1 4 2", 0;
	
	x = 1;
	while(x <= n)	cout << x << ' ', x += 2;
	x = 2;
	while(x <= n)	cout << x << ' ', x += 2;
}