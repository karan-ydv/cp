#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, n;	cin >> x >> n;
	multiset<int> s1 = {x};
	set<int> s2 = {0, x};
	while(n--)
	{
		int p;	cin >> p;
		auto itr = s2.upper_bound(p);
		int r = *itr, l = *--itr;
		s1.erase(s1.lower_bound(r - l));
		s1.insert(p - l);
		s1.insert(r - p);
		s2.insert(p);
		cout << *s1.rbegin() << ' ';
	}
}