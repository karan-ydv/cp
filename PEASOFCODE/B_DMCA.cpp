#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int ans = n;
	for(int i = 2; (1 << i) <= n; i++)
	for(int j = 1; pow(j, i) <= n; j++)
		if(pow(j, i) == n)
		{
			ans = j;
			goto end;
		}
				
	end:
	cout << ans;
}