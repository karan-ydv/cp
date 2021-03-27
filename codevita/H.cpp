#include <bits/stdc++.h>
#define int long long
using namespace std;

int val[5], cost[5];
vector<int> days;
int dp[80001];

int fun(int n, int idx) 
{
	if (idx >= n)	return 0LL;
	if (dp[idx] != 0)
		return dp[idx];

	int mx = 1LL << 50;
	int j = idx;

	for(int i = 0; i < 5; i++)
	{
		while(1)
		{
			if(j >= n) break;
			if(days[j] >= (days[idx] + val[i])) break;
			j++;
		}
		mx = min(mx, fun(n, j) + cost[i]);
	}
	return dp[idx] = mx;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	for(int &x: val)	cin >> x;
	for(int &x: cost)	cin >> x;

	int w, c = 0;	cin >> w;
	for(int i = 0; i < w; i++)
	{
		string s;	cin >> s;
		for(auto it: s)
		{
			c++;
			if(it == '0') continue;
			days.emplace_back(c);
		}
	}

	int n = days.size();
	int ans = fun(n, 0);
	cout << ans;
}