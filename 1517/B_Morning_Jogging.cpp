#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#define f first
#define s second
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, m;	cin >> n >> m;
		pair<int, int> A[n];
		int a[n][m], b[n][m];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)	cin >> a[i][j];
			sort(&a[i][0], &a[i][0] + m);
			A[i] = {0, m - 1};
		}
		for(int j = 0; j < m; j++)
		{
			int mn = 2e9, idx;
			for(int i = 0; i < n; i++)
			if(a[i][A[i].first] < mn)
			{
				mn = a[i][A[i].first];
				idx = i;
			}
			b[idx][j] = a[idx][A[idx].first], A[idx].first++;
			for(int i = 0; i < n; i++) if(i != idx)
			{
				b[i][j] = a[i][A[i].second], A[i].second--;
			}
		}
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cout << b[i][j] << " \n"[j == m - 1];
	}
}