#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int c; cin >> c;
        if(c == 0)
        {
            cout << "2\n1 1\n";
            continue;
        }
        vector<int> ans;
        int x = 0;
        for(int i = 1ll << 61; i; i >>= 1) {
            if((c & i) != (x & i)) {
                int a = (i << 1) - 1;
                x ^= a;
                ans.emplace_back(a);
            }
        }
        cout << ans.size() << '\n';
        for(int x: ans) cout << x << ' ';
        cout << '\n';
    }
}