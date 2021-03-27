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
		int time = 0;
		vector<int> p(n);
		p[n - 1] = 1;
		vector<pair<int, int>> op;
		for(int i = 0; i < n - 1; i++) {
			time += (n - 1 - i) * (n - 1 - i);
			op.emplace_back(i + 1, n);
			p[i] = i + 2;
		}
		cout << time << '\n';
		for(auto x: p)	cout << x << ' ';
		cout << '\n' << op.size() << '\n';
		for(auto [i, j]: op) {
			cout << i << ' ' << j << '\n';
		}
	}
}