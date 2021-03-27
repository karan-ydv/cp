#include <bits/stdc++.h>
#define int long long
using namespace std;

int c = 0;
map<pair<int, int>, int> mp;
int query(int l, int r) {
	if(l == r)	return -1;
	assert(c < 20);
	if(mp.count({l, r})) {
		return mp[{l, r}];
	}
	c++;
	cout << "? " << l << ' ' << r << endl;

	int q;	cin >> q;
	return mp[{l, r}] = q;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int smx = query(1, n);
	int l, r, m, ans;
	if(query(1, smx) == smx) {
		l = 1, r = smx - 1;
	}
	else {
		l = smx + 1, r = n;
	}
	if(l > smx) while(l + 1 < r) {	// right
		m = l + r >> 1;
		if(query(smx, m) == smx)
			r = m;
		else
			l = m + 1;
	}
	else while(l + 1 < r) {
		m = l + r >> 1;
		if(query(m, smx) == smx)
			l = m;
		else
			r = m - 1;
	}
	if(l + 1 == r) {
		if(query(l, r) == l)
			l = r;
	}
	cout << "! " << l << endl;
}