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
        int n, m;   cin >> n >> m;
        n += m;
        set<int> set;
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            set.insert(x);
        }
        for(int x: set) cout << x << ' ';
        cout << '\n';
    }
}