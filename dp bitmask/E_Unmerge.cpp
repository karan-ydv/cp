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
		int a[n];
		for(int &x: a)	cin >> x;
		if(a[1] < a[0])
		{
			return cout << "NO", 0;
		}
		vector<int> v1, v2;
		v1.push_back(a[0]);
		v2.push_back(a[1]);
		for(int i = 2; i < n; i++)
		{
			if(a[i])
		}
	}
}