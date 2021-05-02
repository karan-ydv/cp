#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;	cin >> n >> m >> k;
	int ans = n - 1 + m - 1 + n * m;	
	cout << ans << '\n' << string(m - 1, 'L') << string(n - 1, 'U');
	for(int i = 1; i <= n; i++)
	{
		if(i & 1)	cout << string(m - 1, 'R');
		else		cout << string(m - 1, 'L');
		cout << 'D';
	}
}