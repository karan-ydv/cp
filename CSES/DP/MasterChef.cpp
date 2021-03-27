#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int k1, k2;
		string s;	cin >> s >> k1 >> k2;
		int n, x;	n = s.length();
		vector<bool> unlocked(n, true);
		x = k1;	while(x <= n)	unlocked[x - 1] = false, x += k1;
		x = k2;	while(x <= n)	unlocked[x - 1] = false, x += k2;
		stack<int> stk;
		int score = 0, ans = 0;
		for(int i = 0; i < n; i++)
		{
			score += (s[i] == 'W' ? 1 : - 1);
			if(s[i] == 'L' and unlocked[i]){
				stk.push(i);
			}
			while(score <= 0)
			{
				if(stk.empty())	break;
				int p = stk.top();	stk.pop();
				s[p] = 'W';
				score += 2;
				ans ++;
			}
			if(score <= 0)
			{
				cout << "-1\n";
				break;
			}
		}
		if(score > 0)
		cout << ans << '\n' << s << '\n';
	}
}