#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> omset;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, k;	cin >> n >> k;
		int A[n];	for(int &x: A)	cin >> x;
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			omset set;
			unordered_map<int, int> F;
			for(int j = i; j < n; j++)
			{
				F[A[j]]++;
				set.insert({A[j], j});
				int x = min(k, j - i + 1);
				int Bx = set.find_by_order(x - 1)->first;
				if(F.count(F[Bx]))
				{
					cout << i << ' ' << j << ' ' << x << ' ' << Bx << ' ' <<  F[Bx] << '\n';
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}