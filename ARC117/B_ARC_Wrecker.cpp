#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int mod = 1e9+7;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	set<int> set;
	for(int i = 0; i < n; i++) {
		int x;	cin >> x;
		set.insert(x);
	}
	auto itr = set.begin();
	int ans = 1, prev = 0;
	while(itr != set.end())
	{
		ans = ans * (*itr - prev + 1) % mod;
		prev = *itr;
		++itr;
	}
	cout << ans;
}