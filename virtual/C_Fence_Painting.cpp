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
		int n, m;	cin >> n >> m;
		int a[n];	for(int &x: a)	cin >> x;
		int b[n];	for(int &x: b)	cin >> x;
		int c[m];	for(int &x: c)	cin >> x;
		
		unordered_map<int, queue<int>> mp;
		unordered_map<int, int> color;
		for(int i = 0; i < n; i++) {
			if(b[i] != a[i])
				mp[b[i]].push(i);
			else if(!color.count(a[i]))
				color[a[i]] = i;
		}

		stack<int> temp;
		vector<int> paint(m, -1);
		for(int i = 0; i < m; i++) {
			if(mp[c[i]].size())
			{
				while(!temp.empty())
				{
					int x = temp.top();
					paint[x] = mp[c[i]].front();
					temp.pop();
				}
				paint[i] = mp[c[i]].front();
				color[c[i]] = mp[c[i]].front();
				a[mp[c[i]].front()] = c[i];
				mp[c[i]].pop();
			}
			else if(color.count(c[i]))
			{
				while(!temp.empty())
				{
					int x = temp.top();
					paint[x] = color[c[i]];
					temp.pop();
				}
				paint[i] = color[c[i]];
			}
			else	temp.push(i);
		}
		while(!temp.empty())
		{
			// cout << 'x';
			if(!color.count(c[temp.top()]))
				break;
			paint[temp.top()] = color[c[temp.top()]];
			temp.pop();
		}
		
		bool flag = true;
		for(int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				flag = false;
				break;
			}
		}
		for(int i = 0; i < m; i++) {
			if(paint[i] == -1) {
				flag = false;
				break;
			}
		}
		// for(int &x: a)	cout << x << ' ';	cout << '\n';
		// for(int &x: b)	cout << x << ' ';	cout << '\n';
		// for(int &x: paint)	cout << x << ' ';	cout << '\n';
		if(flag)
		{
			cout << "YES\n";
			for(auto &x: paint)	cout << x + 1 << ' ';
			cout << '\n';
		}
		else	cout << "NO\n";
	}
}