#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;	cin >> a >> b;
	if(a + b >= 15 and b >= 8)
		return cout << "1", 0;
	if(a + b >= 10 and b >= 3)
		return cout << "2", 0;
	if(a + b >= 3)
		return cout << "3", 0;
	cout << "4";
}