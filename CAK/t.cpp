#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[100] = {0};

	for(int i = 0; i < 5; i++)
	{
		for(int j = 1; j <= 30; j++)
			cout << j << ' ';
		cout << '\n';
		for(int j = 1; j <= 30; j++)
			cout << a[j - 1] << ' ';
	}
}