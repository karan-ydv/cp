#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;	cin >> n;
	int a[n + 2];
	a[0] = 2e9; a[n + 1] = 0;

	int end[n + 2], beg[n + 2];
	end[0] = end[n + 1] = 0;
	beg[0] = beg[n + 1] = 0;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] > a[i - 1])	end[i] = end[i - 1] + 1;
		else				end[i] = 1;
	}
	for(int i = n; i >= 1; i--)
	{
		if(a[i] < a[i + 1])	beg[i] = beg[i + 1] + 1;
		else				beg[i] = 1;
	}

	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, end[i - 1] + 1);
		ans = max(ans, beg[i + 1] + 1);
		if(a[i + 1] - a[i - 1] > 1)
			ans = max(ans, end[i - 1] + beg[i + 1] + 1);
	}
	
	cout << ans;
}