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
		int cnt = 0;
		for(int i = 1; i < n; i++) {
			if(a[i] < a[i - 1])	cnt++;
		}
		if(cnt > n / 2) {
			cnt = 1;
			int K = (1 << 30) - 1;
			for(int &x: a)	x ^= K;
			for(int i = 1; i < n; i++) {
				if(a[i] < a[i - 1])	cnt++;
			}
			cout << cnt << '\n';
			cout << "3 " << n << " " << K << '\n';
		}
		else	cout << cnt << '\n';

		for(int i = 1; i < n; i++) {
			if(a[i] < a[i - 1])
			cout << "2 " << i + 1 << " " << a[i - 1] - a[i] << '\n';
		}
	}
}