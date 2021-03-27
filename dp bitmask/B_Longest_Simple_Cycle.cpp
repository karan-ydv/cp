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
		int c[n], b[n], a[n];
		for(int &x: c)	cin >> x;
		for(int &x: a)	cin >> x;
		for(int &x: b)	cin >> x;

		int ans = 0, sum = abs(a[1] - b[1]);
		for(int i = 1; i < n - 1; i++)
		{
			ans = max(ans, sum + 1 + c[i]);
			sum = max(abs(a[i + 1] - b[i + 1]), sum + c[i] - abs(a[i + 1] - b[i + 1]) + 1);
			if(a[i + 1] == b[i + 1])
			{
				ans = max(ans, sum);
				sum = 0;
			}
		}
		sum += c[n - 1] + 1;
		ans = max(ans, sum);
		cout << ans << '\n';
	}
}