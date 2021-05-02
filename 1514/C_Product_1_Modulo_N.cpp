#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, p = 1;	cin >> n;
	set<int> set;
	for(int i = 1; i < n; i++)
	if(__gcd(i, n) == 1)
	{
		set.insert(i);
		p = p * i % n;
	}

	if(p != 1)	set.erase(p);
	
	cout << set.size() << '\n';
	for(int x: set)	cout << x << ' ';
}