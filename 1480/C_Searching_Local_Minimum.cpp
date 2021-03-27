#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	int n;	cin >> n;
	vector<int> a(n + 2, -1);
	a[0] = a[n + 1] = 1 << 30;

	int beg = 2, end = n - 1;
	while(beg <= end)
	{
		int mid = (beg + end) / 2;

		for(int i : {mid - 1, mid, mid + 1}) if(a[i] == -1)
			cout << "? " << i << endl,		cin >> a[i];

		for(int i : {mid - 1, mid, mid + 1})
		if(a[i] < a[i - 1] and a[i] < a[i + 1])
			return cout << "! " << i << endl, 0;
		
		if(a[mid - 1] < a[mid])	end = mid - 1;
		else					beg = mid + 1;
	}
}