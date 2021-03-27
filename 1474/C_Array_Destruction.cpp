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
		int n;	cin >> n;
		n <<= 1;
		unordered_map<int, int> mp, mp2;
		int a[n];	for(int& x: a)	cin >> x, mp[x]++;
		sort(a, a + n);
		int i, j, x;
		for(i = 0; i < n - 1; i++)
		{
			mp2 = mp;
			bool flag = true;
			x = a[i] + a[n - 1];
			for(j = n - 1; j >= 0; j--)
			if(mp2[a[j]])
			{
				if(mp2[x - a[j]] == 0)
				{
					flag = false;
					break;
				}
				if(a[j] == x - a[j] and mp2[a[j]] < 2)
				{
					flag = false;
					break;
				}
				mp2[a[j]]--;
				mp2[x - a[j]]--;
				x = a[j];
			}
			if(flag)	break;
		}
		if(i  == n - 1)	cout << "NO\n";
		else
		{
			int x = a[i] + a[n - 1];
			cout << "YES\n" << x << '\n';
			for(int i = n - 1; i >= 0; i--)
			if(mp[a[i]])
			{
				cout << a[i] << ' ' << x - a[i] << '\n';
				mp[a[i]]--;
				mp[x - a[i]]--;
				x = a[i];
			}
		}
	}
}