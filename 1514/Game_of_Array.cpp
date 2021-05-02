#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		set<int> set;
		for(int i = 0; i < n; i++) {
			int x;	cin >> x;
			set.insert(x);
		}
		if(set.size() & 1)
			cout << "Raju\n";
		else
			cout << "Aman\n";
	}
}