#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	bool a[n + 1] = {0};
	for(int i = 0; i < m; i++) {
		int x, y;	cin >> x >> y;
		a[x] = a[y] = 1;
	}
	cout << n - 1 << '\n';
	for(int i = 1; i <= n; i++) {
		if(!a[i]) {
			for(int j = 1; j <= n; j++)
			if(j != i)
			cout << i << ' ' << j << '\n';
			break;
		}
	}

}