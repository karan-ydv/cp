#include <bits/stdc++.h>
using namespace std;

int n, m, h, N;
vector<int> t, d;

void apply(int p, int value) {
	t[p] = value;
	if (p < N) d[p] = value;
}
void push(int x) {
	if(x < N and d[x] != -1) {
		apply(x << 1, d[x]);
		apply(x << 1|1, d[x]);
		d[x] = -1;
	}
}

int L, R, i, V;
void assign(int x = 1, int lx = 1, int rx = N + 1) {
	if(lx >= R or rx <= L)	return;
	if(lx >= L and rx <= R)	return apply(x, V);
	int m = (lx + rx) / 2;
	assign(x << 1, lx, m);
	assign(x << 1|1, m, rx);
	t[x] = max(t[x << 1], t[x << 1|1]);
}

void visible(int x = 1, int lx = 1, int rx = N + 1) {
	// cerr << x << ' ' << "lx = " << lx << " rx = " << rx << endl;
	if(lx > R or rx < L or lx == rx)	return;
	push(x);
	if(t[x] <= V)
	{
		L = min(L, lx);
		R = max(R, rx);
		// cerr << "L = " << L << " R = " << R << endl;
		return;
	}
	int m = (lx + rx) / 2;
	if(m  == lx or m == rx)
		return;
	if(m > R)
	{
		visible(x << 1, lx, m);
		if(m == R)
		visible(x << 1|1, m, rx);

	}
	else if(m < L)
	{
		visible(x << 1|1, m, rx);
		if(m == L)
			visible(x << 1, lx, m);
	}
	else
	{
		visible(x << 1, lx, m);
		visible(x << 1|1, m, rx);
	}
	// cerr << "L = " << L << " R = " << R << endl  << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	N = 1;	while(N < n) N <<= 1;
	t = vector<int>(2 * N, 1 << 30);
	d = vector<int>(N, -1);

	for(int i = 0; i < n; i++)		cin >> t[N + i];
	for(int i = N - 1; i > 0; i--)	t[i] = max(t[i << 1], t[i << 1|1]);
	
	while(m--)
	{
		int op;	cin >> op;
		if(op == 1) {
			cin >> i;
			V = t[N + i - 1];
			L = i;
			R = i + 1;
			visible();
			cout << R - L << '\n';
		}
		else if(op == 2) {
			cin >> L >> V;
			R = L + 1;
			assign();
		}
		else {
			cin >> L >> R >> V;
			R++;
			assign();
		}
	}
}