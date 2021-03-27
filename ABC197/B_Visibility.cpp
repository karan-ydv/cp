#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, w, x, y;	cin >> h >> w >> x >> y;
	string s[h];	for(string &v: s)	cin >> v;

	x--, y--;
	int ans = 1;
	for(int i = 1; x + i < h; i++) {
		if(s[x + i][y] == '.')	ans++;
		else					break;
	}
	for(int i = 1; y + i < w; i++) {
		if(s[x][y + i] == '.')	ans++;
		else					break;
	}
	for(int i = 1; x - i >= 0; i++) {
		if(s[x - i][y] == '.')	ans++;
		else					break;
	}
	for(int i = 1; y - i >= 0; i++) {
		if(s[x][y - i] == '.')	ans++;
		else					break;
	}
	cout << ans;
}