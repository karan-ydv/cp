#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	char A[10][10], B[10][10];
	for(int i = 0; i < 10; i++)
	{
		char c;
		if(i & 1)	c = '*';
		else		c = '.';
		for(int j = 0; j < 10; j++)
		{
			A[i][j] = c;
			c = char('*' + '.' - c);
			B[i][j] = c;
		}
	}
	while(t--)
	{
		int n, m;	cin >> n >> m;
		string s[n];
		for(int i = 0; i < n; i++)	cin >> s[i];
		int count1 = 0, count2 = 0;
		int op1 = 0, op2 = 0;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			count1 += (A[i][j] == '*');
			count2 += (B[i][j] == '*');
			op1 += (s[i][j] != A[i][j]);
			op2 += (s[i][j] != B[i][j]);
		}
		int ans;
		if(count1 > count2)
			ans = op1;
		else if (count2 > count1)
			ans = op2;
		else	ans = min(op1, op2);
		cout << ans << '\n';
	}
}