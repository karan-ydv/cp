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
		string s;	cin >> s;
		int n = s.length();
		priority_queue<pair<int, int>> pq;
		for(int i = 0; i < n;)
		{
			int j = i + 1;
			while(j < n and s[j] == s[i]) j++;
			pq.push({j - i, n - i});
			i = j;
		}
		vector<bool> deleted(n, false);
		int ans = 0;
		for(int i = 0; i < n;)
		if(!deleted[i])
		{
			above:
			auto [q, p] = pq.top();	pq.pop();
			if(deleted[n - p])	goto above;
			deleted[n - p] = true;
			p--, q--;	if(q)	pq.push({q, p});
			while(i < n and deleted[i]) i++;
			int j = i;
			while(j < n and s[j] == s[i])
				deleted[j++] = true;
			i = j;
			ans++;
		}
		else i++;
		cout << ans << '\n';
	}
}