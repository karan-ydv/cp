#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;	cin >> n >> m >> k;
	int a[n];	for(int &x: a)	cin >> x;
	int b[m];	for(int &x: b)	cin >> x;
	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0, ans = 0;
	while(i < n and j < m)
	{
		if(b[j] <= a[i] + k  and b[j] >= a[i] - k) {
			ans ++, i++, j++;
		}
		else if(a[i] + k < b[j] ) {
			i++;
		}
		else {
			j++;
		}
	}
	cout << ans;
}