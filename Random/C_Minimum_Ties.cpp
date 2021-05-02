#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int A[n][n];
		if(n & 1)
		{
			for(int i = 0; i < n; i++)
			{
				int c = 0;
				for(int j = 0; j < n; j++)
				{
					A[i][] = 1;
				}
			}
			for(int i = 0; i < n - 1; i++)
			{
				for(int j = i + 1; j < n; j++)
				{
					A[i].emplace_back(1);

				}
			}
		}
		else
		{

		}
	}
}