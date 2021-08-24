#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct node {
    int mx{0}, pref{0}, prefcnt{0}, suff{0}, suffcnt{0}, n{0};
};
const int N = 3e5+69;
node t[2 * N];

int sumofap(int n, int end)
{
    int beg = max(int(1), end - n + 1);
    return (beg + end) * n / 2;
}

node combine(node& a, node& b)
{
    if(a.n == 0)    return b;
    if(b.n == 0)    return a;
	node res;
    res.n = a.n + b.n;
    res.pref = a.pref;
    res.suff = b.suff;
    res.prefcnt = a.prefcnt + (a.prefcnt == a.n and a.pref == b.pref) ? b.prefcnt : 0;
    res.suffcnt = b.suffcnt + (b.suffcnt == b.n and a.suff == b.pref) ? a.suffcnt : 0;
    res.mx = max(a.mx, b.mx);
    if(a.suff == b.pref)
        res.mx = max(res.mx, sumofap(a.suffcnt + b.prefcnt, a.suff));
	return res;
}

int n, m;

int range_query(int l, int r) {  // query on interval [l, r)
	node resl, resr;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l & 1) resl = combine(resl, t[l++]);
		if(r & 1) resr = combine(t[--r], resr);
	}
	return combine(resl, resr).mx;
}
void modify(int p, int value) {  // set value at position p
    p += n;
	t[p].pref = t[p].suff = t[p].mx = value;
	for( ; p > 1; p >>= 1)
	if(p & 1)	t[p >> 1] = combine(t[p^1], t[p]);
	else		t[p >> 1] = combine(t[p], t[p^1]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for(int i = n; i < 2 * n; i++)
	{
        t[i] = node();
		cin >> t[i].mx;
        t[i].pref = t[i].suff = t[i].mx;
        t[i].suffcnt = t[i].prefcnt = t[i].n = 1;
	}
	for(int i = n - 1; i > 0; i--)
		t[i] = combine(t[i << 1], t[i << 1 | 1]);
	
	while(m--)
	{
        int t;  cin >> t;
        if(t == 1)
        {
            int l, r;   cin >> l >> r;
            // cerr << "l = " << l << " r = " << r << '\n';
            cout << range_query(l - 1, r) << ' ';
        }
        else
        {
            int x, v;   cin >> x >> v;
            // cerr << "x = " << x << " v = " << v << '\n';
            modify(x - 1, v);
        }
	}
}