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
		int n, k;	cin >> n >> k;
		int h[n + 1];
		for(int i = 0; i < n; i++)	cin >> h[i];
		h[n] = -1;

		int sum = 0, i = 0;
		while(i < n - 1)
		{
			if(h[i] < h[i + 1]) {
				h[i]++;
				sum ++;
				if(sum == k)	break;
				i = 0;
				continue;
			}
			i ++;
		}
		if(i == n - 1)	cout << "-1\n";
		else			cout << i + 1 << '\n';
	}
}