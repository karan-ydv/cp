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
		int a[n];	for(int& x: a)	cin >> x;

		int beg = 0, end = 1e12, ans;
		auto possible = [&](int m) {
			int sum = a[0] + m;
			for(int i = 1; i < n; i++) {
				if(a[i] * 100 > k * sum)
					return false;
				sum += a[i];
			}
			return true;
		};
		while(beg <= end)
		{
			int mid = beg + end >> 1;
			if(possible(mid))
				ans = mid, end = mid - 1;
			else
				beg = mid + 1;
		}
		cout << ans << '\n';
	}
}
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
		int a[n];	for(int& x: a)	cin >> x;

		int beg = 0, end = 1e12, ans;
		auto possible = [&](int m) {
			int sum = a[0] + m;
			for(int i = 1; i < n; i++) {
				if(a[i] * 100 > k * sum)
					return false;
				sum += a[i];
			}
			return true;
		};
		while(beg <= end)
		{
			int mid = beg + end >> 1;
			if(possible(mid))
				ans = mid, end = mid - 1;
			else
				beg = mid + 1;
	\	}
		cout << ans << '\n';
	}
}