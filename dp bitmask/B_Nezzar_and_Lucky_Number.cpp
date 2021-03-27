#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v[10];
	for(int i = 1; i <= 100; i++) {
		int j = i;
		while(j) {
			v[j % 10].emplace_back(i);
			j /= 10;
		}
	}

	bitset<101> A[10];
	for(int i = 1; i < 10; i++) {
		A[i][0] = 1;
		for(auto x: v[i]) {
			for(int j = 0; j < 100 / i; j++)
			A[i] |= A[i] << x;
		}
	}

	int t;	cin >> t;
	while(t--)
	{
		int q, d;	cin >> q >> d;
		while(q--)
		{
			int x;	cin >> x;
			if(x > 11 * d) cout << "YES\n";
			else
			{
				if(A[d][x])	cout << "YES\n";
				else		cout << "NO\n";
			}
		}
	}
}