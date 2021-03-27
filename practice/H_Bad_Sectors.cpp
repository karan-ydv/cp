#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int n, k;
int t[2 * N];
int h, d[N];

void apply(int p, int value) {
	t[p] = value;
	if (p < n) d[p] = value;
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != -1) {
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = -1;
		}
	}
}

void assign(int l, int r, int value) {
	l += n, r += n;
	push(l);
	push(r - 1);
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, value);
		if (r&1) apply(--r, value);
	}
}

int query(int l) {
	l += n;
	push(l);
	return t[l];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> n >> k >> s;
	fill_n(d, N, -1);
	h = sizeof(int) * 8 - __builtin_clz(n);

	for(int i = 0; i < n; i++) {
		if(s[i] == '*') {
			assign(max(0, i - k), min(i + k + 1, n), 1);
		}
	}
	for(int i = 0; i < n; i++) {
		cout << (query(i) ? '*' : '.');
	}
}