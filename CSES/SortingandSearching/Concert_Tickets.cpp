#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	multiset<int> set;
	for(int i = 0; i < n; i++) {
		int x;	cin >> x;
		set.insert(x);
	}
	while(m--)
	{
		int x, val;	cin >> x;
		if(set.empty() or x < *set.begin())	val = -1;
		else
		{
			auto itr = set.lower_bound(x);
			if(itr != set.end() and *itr == x)
			{
				val = x;
			}
			else val = *--itr;
			set.erase(itr);
		}
		cout << val << '\n';
	}
}