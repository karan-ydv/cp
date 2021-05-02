#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n]; for(int &x: a)	cin >> x;
	int sum = 0, ans = a[0];
	for(int x: a)
	{
		sum += x;
		ans = max(ans, sum);
		if(sum < 0)	sum = 0;
	}
	cout << ans;
}