#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x;
		vector<int> ans;
		for(int x: a) {
			if(x & 1)	ans.emplace_back(x);
		}
		for(int x: a) {
			if(!(x & 1))	ans.emplace_back(x);
		}
		for(int x: ans)	cout << x << ' ';
		cout << '\n';
	}
}