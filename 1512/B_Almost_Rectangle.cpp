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
		int n;	cin >> n;
		string s[n];
		for(auto &x: s)	cin >> x;
		vector<pair<int, int>> v;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			if(s[i][j] == '*')
			{
				v.emplace_back(i, j);
			}
		}
		pair<int, int> a = v[0], b = v[1];
		swap(a.second, b.second);
		if(s[a.first][a.second] == '*')
		{
			if(a.first == b.first)
			{
				a.first = b.first = (a.first + 1) % n;
			}
			else
			{
				a.second = b.second = (a.second + 1) % n;
			}
		}
		s[a.first][a.second] = '*';
		s[b.first][b.second] = '*';
		for(auto &x: s)	cout << x << '\n';
	}
}