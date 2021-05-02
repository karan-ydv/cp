#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n + 2], pref[n + 2], suff[n + 2];
	for(int i = 1; i <= n; i++)	cin >> a[i];

	pref[0] = suff[n + 1] = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		pref[i] = max(pref[i - 1] + a[i], -sum);
	}
	sum = 0;
	for(int i = n; i >= 1; i--)
	{
		sum += a[i];
		suff[i] = max(suff[i + 1] + a[i], -sum);
	}
	// for(int i = 1; i <= n; i++)	cout << pref[i] << ' ';	cout << '\n';
	// for(int i = 1; i <= n; i++)	cout << suff[i] << ' ';	cout << '\n';

	int ans = sum;
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, pref[i - 1] + suff[i]);
	}
	
	cout << ans << '\n';
}