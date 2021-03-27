#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1001][1001];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	while(m--)
	{
		int u, v;	cin >> u >> v;
		int x, y;	cin >> x >> y;
		a[u][v]++;
		a[x][y]++;
	}
	int s1 = 0, s2 = 0;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		if((i+j)&1)
		{
			s1 ++;
			if(a[i][j] == 0)		s2++;
		}
		else
		{
			s2++;
			if(a[i][j] == 0)		s1++;
		}
	}
	cout << max(s1, s2);
}