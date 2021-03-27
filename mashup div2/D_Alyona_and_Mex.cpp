#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n]; for(int &x: a)	cin >> x;
	sort(a, a + n);
	int c = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] >= c)	c++;
	}
	cout << c;
}