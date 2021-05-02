#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; i++)
#define ROF(i, j, k) for(int i = j; i > k; i--)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	if(k == 0)
	{
		FOR(i, 0, n)	cout << i + 1 << ' ';
		return 0;
	}
	ordered_set set;
	FOR(i, 0, n)	set.insert(i + 1);
	int x = 0;
	ROF(i, n, 0)
	{
		x = (x + k % i) % i;
		auto itr = set.find_by_order(x);
		cout << *itr << ' ';
		set.erase(itr);
	}
}