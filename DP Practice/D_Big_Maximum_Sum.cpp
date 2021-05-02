#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 55, M =5e3+5;
// int A[N][M];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	vector<int> A[n + 1];
	int pref[n + 1], suff[n + 1], meks[n + 1], tot[n + 1] = {0};
	int ans = -1e18;
	for(int i = 1; i <= n; i++)
	{
		int x;	cin >> x;
		A[i].resize(x);
		for(int &x: A[i])	cin >> x, tot[i] += x;
		int sum = 0;
		meks[i] = A[i][0];
		for(int v: A[i])
		{
			sum += v;
			meks[i] = max(meks[i], sum);
			if(sum < 0)	sum = 0;
		}
		pref[i] = A[i][0];
		suff[i] = A[i][x - 1];
		sum = 0;	for(int j = 0; j < x; j++)		sum += A[i][j], pref[i] = max(pref[i], sum);
		sum = 0;	for(int j = x - 1; j >= 0; j--)	sum += A[i][j], suff[i] = max(suff[i], sum);
	}
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		int x;	cin >> x;
		ans = max(ans, meks[x]);
		ans = max(ans, sum + pref[x]);
		sum = max(0LL, sum + tot[x]);
		sum = max(sum, suff[x]);
	}
	cout << ans;
}