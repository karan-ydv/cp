#include <bits/stdc++.h>
#define int long long
using namespace std;

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
	cout << set.size();
}