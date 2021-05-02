#include <bits/stdc++.h>
#define int long long
using namespace std;

int L[100];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	L[0] = 2;
	L[1] = 1;
	int n;	cin >> n;
	for(int i = 2; i <= n; i++)
		L[i] = L[i - 1] + L[i - 2];
	cout << L[n];
}