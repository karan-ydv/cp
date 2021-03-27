#include <bits/stdc++.h>
using namespace std;

struct pos
{
	int mx, mn, val;
	pos() {
		mx = 0, mn = 0, val = 0;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
	{
		string s;
		int n, m;
		cin >> n >> m >> s;
		pos pref[n], suff[n];

		pref[0].val = ((s[0] == '+') ? 1 : -1);
		pref[0].mx = max(0, pref[0].val);
		pref[0].mn = min(0, pref[0].val);
		for(int i = 1; i < n; i++)
		{
			pref[i].val = pref[i - 1].val + (s[i] == '+' ? 1 : -1);
			pref[i].mx = max(pref[i - 1].mx, pref[i].val);
			pref[i].mn = min(pref[i - 1].mn, pref[i].val);
		}
		suff[n - 1].val = ((s[n - 1] == '+') ? 1 : -1);
		suff[n - 1].mx = max(0, suff[n - 1].val);
		suff[n - 1].mn = min(0, suff[n - 1].val);
		for(int i = n - 2; i >= 0; i--)
		{
			suff[i].val = (s[i] == '+' ? 1 : -1);
			suff[i].mx = max(0, suff[i].val);
			suff[i].mn = min(0, suff[i].val);
			suff[i].mx = max(suff[i].mx, suff[i].val + suff[i + 1].mx);
			suff[i].mn = min(suff[i].mn, suff[i].val + suff[i + 1].mn);
			suff[i].val = suff[i + 1].val + (s[i] == '+' ? 1 : -1);
		}
		while(m--)
		{
			int l, r;	cin >> l >> r;
			l -= 2;

			pos v, w;
			if(l >= 0)	v = pref[l];
			if(r < n)	w = suff[r];

			v.mx = max(v.mx, v.val + w.mx);
			v.mn = min(v.mn, v.val + w.mn);
			cout << (v.mx - v.mn + 1) << '\n';
		}
	}
}