#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int s = n * (n + 1) / 2;
	for(int i = 1; i < n; i++) {
		int x;	cin >> x;
		s -= x;
	}
	cout << s;
}