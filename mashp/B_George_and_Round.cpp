#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int a[n], b[m];
	for(int &x: a)	cin >> x;
	for(int &x: b)	cin >> x;

	int j = 0, i;
	for(i = 0; i < n and j < m; j++) {
		if(a[i] <= b[j])	i++;
	}
	int ans = n - i;
	cout << ans;
}