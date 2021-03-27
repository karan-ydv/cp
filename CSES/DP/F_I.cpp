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
		int k;	cin >> k;
		int m = (k + 1) / 2;
		int spaces = m - 1;
		int times = 4 + (k - 11) / 2;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 0; j < spaces; j++)
				cout << " ";
			for(int j = 0; j < times; j++)
				cout << i;
			cout << '\n';
			spaces--;
		}
		spaces = 1;
		for(int i = m + 1; i <= k; i++)
		{
			for(int j = 0; j < spaces; j++)
				cout << " ";
			for(int j = 0; j < times; j++)
				cout << i;
			cout << '\n';
			spaces++;
		}
	}
}