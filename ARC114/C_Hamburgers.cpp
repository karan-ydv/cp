#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	int nb, ns, nc;	cin >> nb >> ns >> nc;
	int pb, ps, pc;	cin >> pb >> ps >> pc;
	int r;	cin >> r;
	int bcnt = 0, scnt = 0, ccnt = 0;
	for(char c: s)	bcnt += (c == 'B'), scnt += (c == 'S'), ccnt += (c == 'C');
	int beg = 0, end = 1e15, ans;
	while(beg <= end)
	{
		int mid = beg + end >> 1;
		int cst = pb * max(mid * bcnt - nb, 0ll) + ps * max(mid * scnt - ns, 0ll) + pc * max(mid * ccnt - nc, 0ll);
		if(cst <= r)	ans = mid, beg = mid + 1;
		else			end = mid - 1;
	}
	cout << ans;
}