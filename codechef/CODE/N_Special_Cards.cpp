#include <bits/stdc++.h>
// #define int long long
using namespace std;

struct card {
	char color;
	int red, blue;
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	card cards[n];
	for(auto c: cards)	cin >> c.color >> c.red >> c.blue;
	vector<int> dp(1 << n, 1 << 30);
	vector<int> blue(1 << n, 0), red(1 << n, 0);
	vector<int> rt(1 << n, 0), bt(1 << n, 0);
	dp[0] = 0;
	for(int i = 1; i < 1 << n; i++)
	{
		for(int j = 1, k = 0; k < n; j <<= 1, k++) 
		if(j & 1)
		{
			int t, r, b;
			int rm = max(cards[k].red - red[i ^ j], 0);
			int bm = max(cards[k].blue - blue[i ^ j], 0);
			t = dp[i ^ j] + max(rm, bm) + 1;
			
			r = rt[i ^ j] + max(rm, bm) - rm;
			b = bt[i ^ j] + max(rm, bm) - bm;
			if(t < dp[i])
			{
				dp[i] = t;
				rt[i] = r;
				bt[i] = b;
			}
			else if(t == dp[i])
			{
				
			}
		}
		red[i] = red[i ^ j] + cards[k].color == 'R';
		blue[i] = blue[i ^ j] + cards[k].color == 'B';
	}
	cout << dp[(1 << n) - 1];