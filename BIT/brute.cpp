#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = rand() % 100 + 1;
	cout << n << '\n';
	for(int i = 0; i < n; i++)
	cout << rand() % 100 + 1 << ' ';
	cout << '\n';
	
	int q = rand() % 100 + 1;
	cout << q << '\n';
	while(q--)
	{
		int i = rand() % n + 1;
		int j = rand() % n + 1;
		if(i > j) swap(i, j);
		int k = rand() % 100;
		cout << i << ' ' << j << ' ' << k << '\n';
	}
}