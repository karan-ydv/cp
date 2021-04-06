#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n];	for(int &x: a)	cin >> x;
	cout << "1 1\n";
	cout << -a[0] << '\n';
	if(n == 1)
	{
		return cout << "1 1\n" << "0\n" << "1 1\n" << "0\n", 0;
	}
	cout << "2 " << n << '\n';
	for(int i = 1; i < n; i++)
	{
		cout << a[i] * (n - 1) << ' ';
	}
	cout << "\n1 " << n << "\n0 ";
	for(int i = 1; i < n; i++)
	{
		cout << - a[i] * n << ' ';
	}

}