#include <bits/stdc++.h>
#define int long long
using namespace std;


#define N 200005
int parent[N], weight[N], w2[N];
int find(int x)
{
	if(parent[x]==x)    return x;
	return parent[x]=find(parent[x]);
}
void onion(int x,int y)
{
	x=find(x);
	y=find(y);
	if(weight[x]>weight[y]) swap(x,y);
	if(x!=y)
	{
		parent[x]=y;
		weight[y]+=weight[x];
		w2[y] += w2[x];
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, p;	cin >> n;
	// int a[n];	for(int &x: a)	cin >> x;
	for(int i = 1; i <= n; i++) {
		cin >> w2[i];
	}
	fill_n(weight, N, 1);
	iota(parent, parent + N, 0);
	
	cin >> p;
	while(p--)
	{
		int u, v;	cin >> u >> v;
		onion(u, v);
	}
	int mx = -1, idx;
	for(int i = 1; i <= n; i++) {
		if(find(i) == i) {
			if(mx < w2[i])
			{
				idx = i;
				mx = w2[i];
			}
			if(mx == w2[i])
			{
				if(weight[i] < weight[idx])
					idx = i;
			}
		}
	}
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		if(find(i) == idx) {
			v.emplace_back(i);
		}
	}
	sort(v.begin(), v.end());
	for(int x: v)	cout << x << ' ';
}