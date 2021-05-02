#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x, c = 1;	cin >> n >> x;
	pair<int, int> a[n];	for(auto &[x, y]: a)	cin >> x, y = c++;
	sort(a, a + n);
	for(int i = 0; i < n; i++)
	if(a[i].first < x)
	{
		int beg = i + 1, end = n - 1, key = x - a[i].first;
		while(beg <= end)
		{
			int mid = beg + end >> 1;
			if(a[mid].first == key)
				return cout << a[i].second << ' ' << a[mid].second, 0;
			else if(a[mid].first < key)
				beg = mid + 1;
			else
				end = mid - 1;
		}
	}
	else break;
	cout << "IMPOSSIBLE";
}