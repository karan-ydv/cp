#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
        for(int _ = 1; _ <= t; _ ++) {
            cout << "Case #" << _ << ": ";
            int n, q;  cin >> n >> q;
            set<pair<int, int>> set;
            for(int i = 0; i < n; i++)
            {
                int x, y; cin >> x >> y;
                set.insert({x, y});
            }
            set.insert({-3e18, -3e18});
            set.insert({3e18, 3e18});
            while(q--)
            {
                int d;  cin >> d;
                pair<int, int> f = {d, -2e9};
                auto itr2 = set.lower_bound(f);
                auto itr1 = itr2; itr1--;
                auto [l1, r1] = *itr1;
                auto [l2, r2] = *itr2;
                if(l1 <= d and d <= r1)
                {
                    cout << d << ' ';
                    set.erase(itr1);
                    if(d - 1 >= l1) set.insert({l1, d - 1});
                    if(d + 1 <= r1) set.insert({d + 1, r1});
                }
                else if(l2 <= d and d <= r2)
                {
                    cout << d << ' ';
                    set.erase(itr2);
                    if(d - 1 >= l2) set.insert({l2, d - 1});
                    if(d + 1 <= r2) set.insert({d + 1, r2});
                }
                else if(l2 - d < d - r1)
                {
                    set.erase(itr2);
                    cout << l2 << ' ';
                    if(l2 + 1 <= r2) set.insert({l2 + 1, r2});
                }
                else
                {
                    set.erase(itr1);
                    cout << r1 << ' ';
                    if(r1 - 1 >= l1) set.insert({l1, r1 - 1});
                }
            }
            cout << '\n';
        }
}