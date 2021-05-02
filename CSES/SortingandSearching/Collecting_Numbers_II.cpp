#include <bits/stdc++.h>
#define int long long
using namespace std;

#define f first
#define s second

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;

	int A[n + 1];
	pair<int, int> a[n + 2];
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
		a[i].f = A[i];
		a[i].s = i;
	}

	a[0] = {0, 0};
	a[n + 1] = {n + 1, n + 1};
	sort(a, a + n + 1);

	int ans = 1;
	for(int i = 1; i <= n; i++)
		ans += (a[i].s < a[i - 1].s);
	while(m--)
	{
		int i, j;	cin >> i >> j;
		swap(A[i], A[j]);
		if(A[i] > A[j])	swap(i, j);
		if(A[j] - A[i] <= 2)
		{
			for(int k = A[i]; k <= A[j] + 1; k++)
				ans -= (a[k].s < a[k - 1].s);
			swap(a[A[i]].s, a[A[j]].s);
			for(int k = A[i]; k <= A[j] + 1; k++)
				ans += (a[k].s < a[k - 1].s);
		}
		else
		{
			for(int x: {A[i], A[j]}) for(int k: {x, x + 1})
				ans -= (a[k].s < a[k - 1].s);
			swap(a[A[i]].s, a[A[j]].s);
			for(int x: {A[i], A[j]}) for(int k: {x, x + 1})
				ans += (a[k].s < a[k - 1].s);
		}
		cout << ans << '\n';
	}
}