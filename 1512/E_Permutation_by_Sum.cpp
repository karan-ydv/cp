#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 125250 + 10;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		int k = r - l + 1;
		int A[k];
		iota(A, A + k, 1);
		int sum = k * (k + 1) / 2;
		if(s < sum)
		{
			cout << "-1\n";
			continue;
		}
		int m = n;
		for(int i = k - 1; sum < s and i >= 0; i--, m--)
		{
			// cout << A[i] << ' ';
			sum -= i + 1;
			A[i] = min(m, s - sum);
			sum += A[i];
		}
		// cout << '\n';
		if(sum != s)
		{
			cout << "-1\n";
			continue;
		}
		int ans[n];
		l--;
		vector<bool> taken(n + 1);
		for(int i = l; i < r; i++)
		{
			ans[i] = A[i - l];
			taken[ans[i]] = 1;
		}
		int j = 1;
		for(int i = 0; i < n; i++)
		if(i < l or i >= r)
		{
			while(taken[j]) j++;
			ans[i] = j;
			j++;
		}
		for(int x: ans)		cout << x << ' ';
		cout << '\n';
	}
}