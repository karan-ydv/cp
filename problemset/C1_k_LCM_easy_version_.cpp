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
		int n, k;	cin >> n >> k;
		int a[k];
		if(n & 1) {
				a[0] = n / 2;
				a[1] = n / 2;
				a[2] = 1;
		}
		else {
			n /= 2;
			if(n & 1) {
				a[0] = n - 1;
				a[1] = n - 1;
				a[2] = 2;
			}
			else {
				a[0] = n;
				a[1] = n / 2;
				a[2] = n / 2;
			}
		}
		for(int i = 0; i < k; i++)	cout << a[i] << " \n"[i == k - 1];
	}
}