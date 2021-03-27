#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int v;
	struct node* L;
	struct node* R;
	node() {
		R = L = NULL;
	}
};
int a[100], d[101];
node* f(int b, int end) {
	if(b >= end)	return NULL;
	int mx = 0, j;
	for(int i = b; i < end; i++) {
		if(a[i] > mx) {
			mx = a[i], j = i;
		}
	}
	// cout << mx << ' ';
	node *nd = new node();
	nd -> v = mx;
	nd -> L = f(b, j);
	nd -> R = f(j + 1, end);
	return nd;
}
void dfs(node *root, int h) {
	if(root == NULL)	return;
	// cout << root -> v << ' ';
	d[root -> v] = h;
	dfs(root -> L, h + 1);
	dfs(root -> R, h + 1);
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		node *root = f(0, n);
		// cout << root
		dfs(root, 0);
		// cout << '\n';
		for(int i = 1; i <= n; i++) {
			cout << d[a[i - 1]] << ' ';
		}
		cout << '\n';
	}
}