#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		cin >> a[i][j];

	for(int x = 1; x < 1024; x <<= 1) 
	{
		int i, j, c = 0, d = 0;
		vector<int> v(n, 0);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
				v[i] += ((a[i][j] & x) != 0);
			c += (v[i] == m);
			d += (v[i] == 0);
		}
		if(c + d == n and c % 2 == 0)
			continue;
		cout << "TAK\n";
		for(int i = 0; i < n; i++)
		{
			if(v[i] == m or v[i] == 0)
				cout << "1 ";
			else if(c & 1)
			{
				for(int j = 0; j < m; j++)
				if((a[i][j] & x) == 0)
				{
					cout << j + 1 << " ";
					break;
				}
			}
			else
			{
				for(int j = 0; j < m; j++)
				if((a[i][j] & x) != 0)
				{
					cout << j + 1 << " ";
					c++;
					break;
				}
			}
		}
		return 0;
	}
	cout << "NIE";
}