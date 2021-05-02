#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	multiset<int> set;
	for(int i = 0; i < n; i++)
	{
		int x;	cin >> x;
		auto itr = set.upper_bound(x);
		if(itr != set.end())
			set.erase(itr);
		set.insert(x);
	}
	cout << set.size();
}