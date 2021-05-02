#include <bits/stdc++.h>
#define int long long
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// typedef tree<
// int,
// null_type,
// less<int>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// typedef tree<
// pair<int, int>,
// null_type,
// less<pair<int, int>>,
// rb_tree_tag,
// tree_order_statistics_node_update> ordered_multiset;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace __gnu_pbds;
 
typedef trie<
string,
null_type,
trie_string_access_traits<>,
pat_trie_tag,
trie_prefix_search_node_update>
pref_trie;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
}

#define FOR(i, j, k) for(int i = j; i < k; i++)
#define ROF(i, j, k) for(int i = j; i > k; i--)