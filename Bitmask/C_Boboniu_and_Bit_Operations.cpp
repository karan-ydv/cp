#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = (1 << 9) + 1;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int a[n], b[m];
	for(int &x: a)	cin >> x;
	for(int &x: b)	cin >> x;

	for(int ans = 0; ans < N; ans++) 
	{
		int i, j;
		for(i = 0; i < n; i++) 
		{
			for(j = 0; j < m; j++)
			if((a[i] & b[j] | ans) == ans)
				break;
			if(j == m)	break;
		}
		
		if(i == n) 
		{
			cout << ans;
			break;
		}
	}
}