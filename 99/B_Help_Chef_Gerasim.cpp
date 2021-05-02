#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n];
	map<int, int> mp;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	if(mp.size() == 1)
	{
		return cout << "Exemplary pages.", 0;
	}
	int x = mp.begin()->first;
	int y = mp.rbegin()->first;
	int delta = (y - x);
	if(delta & 1)	return cout << "Unrecoverable configuration.", 0;
	delta /= 2;
	int i = find(a, a + n, x) - a;
	int j = find(a, a + n, y) - a;
	// cout << x << ' ' << y << ' ' << i << ' ' << j << ' ' << delta << '\n';
	i++, j++;
	if(mp.size() == 2)
	{
		if(n != 2)	cout << "Unrecoverable configuration.";
		else
		{
			cout << delta << " ml. from cup #" << i << " to cup #" << j << ".";
		}
		return 0;
	}
	if(mp.size() == 3)
	{
		if(mp[x] == 1 and mp[y] == 1 and mp[x + delta] > 0)
		{
			return cout << delta << " ml. from cup #" << i << " to cup #" << j << ".", 0;
		}
	}
	cout << "Unrecoverable configuration.", 0;
}