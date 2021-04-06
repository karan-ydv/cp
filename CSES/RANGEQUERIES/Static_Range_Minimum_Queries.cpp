#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e5+5;
const int K = log2(MAXN);

int LOG[MAXN];
void preprocess() {
	LOG[1] = 0;
	for (int i = 2; i < MAXN; i++)
		LOG[i] = LOG[i/2] + 1;
}

struct SparseTable {
	typedef int item;
	vector<vector<item>> st;
	int N;

	SparseTable(int n, vector<int> v = {}) {
		N = n;
		st = vector<vector<item>>(N, vector<item>(K + 1));

		for (int i = 0; i < N; i++)
		{
			if(v.size())	st[i][0] = v[i];
			else			cin >> st[i][0];
		}

		for (int j = 1; j <= K; j++)
			for (int i = 0; i + (1 << j) <= N; i++)
				st[i][j] = std::min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
	}
	int min(int L, int R) {		// min in range [L, R]
		int j = LOG[R - L + 1];
		return std::min(st[L][j], st[R - (1 << j) + 1][j]);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	preprocess();
	int n, q;	cin >> n >> q;
	SparseTable st(n);
	while(q--)
	{
		int a, b;	cin >> a >> b;
		cout <<	st.min(a - 1, b - 1) << '\n';
	}
}