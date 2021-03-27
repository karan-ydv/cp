#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

int ncr[1001][1001];
void fn()
{
    ncr[1][0] = 1;
    ncr[1][1] = 1;
    for(int i = 2; i <= 1000; i++)
    {
        ncr[i][0] = 1;
        for(int j = 1; j <= i; j++)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
    }
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fn();
	int t;	cin >> t;
	while(t--)
	{
		int n, k;	cin >> n >> k;
		vector<int> f(n + 1);
		int a[n];	for(int &x: a)	cin >> x, f[x]++;
		sort(a, a + n, greater<int>());
		int b[n + 1];
		partial_sum(a, a + n, b + 1);

		int N = f[a[k - 1]], R;
		for(int i = 0; i < k; i++) {
			if(a[i] == a[k - 1])
			{
				R = k - i;
				break;
			}
		}
		cout << ncr[N][R] << '\n';
	}
}