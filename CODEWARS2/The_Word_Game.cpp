#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n, m;
char A[5][5];
set<string> ans;
pair<int, int> D[] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool valid(int i, int j) {
	if(i < 0 or j < 0)		return false;
	if(i >= n or j >= m)	return false;
	return true;
}

bool possible(string &s, int p, int x, int y, bitset<20> vis)
{
	if(p == s.length())	return true;
	for(auto [dx, dy]: D)
	{
		int x1 = x + dx;
		int y1 = y + dy;
		if(valid(x1, y1))
		if(!vis[x1 * m + y1])
		if(s[p] == A[x1][y1])
		{
			bitset<20> vis2 = vis;
			vis2[x1 * m + y1] = 1;
			if(possible(s, p + 1, x1, y1, vis2))	return true;
		}
	}
	return false;
}

bool possible(string &s)
{
	bitset<20> vis;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	if(s[0] == A[i][j])
	{
		vis[i * m + j] = 1;
		if(possible(s, 1, i, j, vis))
			return true;
		vis[i * m + j] = 0;
	}
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	{
		cin >> A[i][j];
		// cerr << A[i][j] << " \n"[j == m - 1];
	}
	int q;	cin >> q;
	for(int i = 0; i < q; i++) {
		string s;	cin >> s;
		if(possible(s))
			ans.insert(s);
	}

	for(string s: ans)	cout << s << ' ';
}