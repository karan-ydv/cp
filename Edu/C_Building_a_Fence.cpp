#include <bits/stdc++.h>
#define int long long
using namespace std;

struct fence {
	int max, min;
};
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, k;	cin >> n >> k;
		int h[n];	for(int &x: h)	cin >> x;
		fence f[n];
		f[0].min = h[0];
		f[0].max = h[0] + k;
		f[n - 1].min = h[n - 1];
		f[n - 1].max = h[n - 1] + k;
		
		for(int i = 1; i < n - 1; i++)
		{
			f[i].min = h[i];
			f[i].max = h[i] + k - 1 + k;
			f[i].min = (h[i - 1]. )
		}
	}
}