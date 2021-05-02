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
		int n;	cin >> n; n += 2;
		int a[n];	for(int &x: a)	cin >> x;
		sort(a, a + n);
		int sum = accumulate(a, a + n - 1, 0ll);
		int idx = -1;
		for(int i = 0; i < n - 1; i++)
		if(a[i] <= 1e9 and a[i] >= 1)
		{
			if(sum - a[i] == a[n - 1])
			{
				idx = i;
				break;
			}
		}
		if(idx == -1)
		{
			if(sum - a[n - 2] == a[n - 2])
				idx = n - 2;
		}
		if(idx == -1)	cout << "-1";
		else
		{
			int c = 0, i = 0;
			while(c < n - 2)
			{
				if(i != idx)
				{
					cout << a[i] << ' ';
					c++;
				}
				i++;
			}
			
		}
		cout << '\n';
	}
}