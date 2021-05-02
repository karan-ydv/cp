#include <bits/stdc++.h>
using namespace std;

const int MAXSUM = 2e5+5;
bitset<MAXSUM> dp;

bool subsetsum(vector<int> &v, int x)
{
	dp.reset();
	dp[0] = 1;
	for(int val: v)	dp |= (dp << val);
	return dp[x];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	vector<int> a(n);
	int sum = 0, lsb = 0, mn = 100;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		int tz = __builtin_ctz(a[i]);
		if(tz < mn)	lsb = i + 1, mn = tz;
	}

	if(sum & 1)
		cout << '0';
	else if(subsetsum(a, sum >> 1))
		cout << "1\n" << lsb;
	else
		cout << '0';
}