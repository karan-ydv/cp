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
		int e = 0, o = 0;
		int a[n];	for(int& c: a)	cin >> c, e += 1 - (c & 1), o += (c & 1);

		if(o & 1)	cout << "2\n";
		else		cout << "1\n";
	}
}