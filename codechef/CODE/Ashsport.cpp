#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int s[n], r[n];
	for(int i = 0; i < n; i++)
		cin >> s[i] >> r[i];
	
	pair<double, int> v[n];
	for(int i = 0; i < n; i++)
	{
		v[i] = {1.0 / s[i] + 1.0 / r[i], i};
	}
	for(int i = 0; i < n; i++)
	{
		double ratio = (1.0 / s[i] - 1 / s[(i + 1) % n]) / (-1.0 / r[i] + 1 / r[(i + 1) % n]);
	}
}