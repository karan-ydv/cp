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
		sort(a, a + n);
		vector<int> x, y;
		x.push_back(a[0]);
		for(int i = 1; i < n; i++) {
			if(a[i] == x.back()) {
				y.push_back(a[i]);
			}
			else x.push_back(a[i]);
		}
		for(int v: x)	cout << v << ' ';
		for(int v: y)	cout << v << ' ';
		cout << '\n';
	}
}