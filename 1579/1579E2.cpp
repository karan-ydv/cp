#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        ordered_multiset s;
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            int x;  cin >> x;
            int m = s.order_of_key({x, 0});
            int k = s.order_of_key({x, n});
            ans += min(m, i - k - 1);
            s.insert({x, i});
        }
        cout << ans << '\n';
    }
}