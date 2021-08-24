#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        sort(a, a + n);
        // for(int x: a)   cerr << x << ' ';
        // cerr << '\n';
        int ans = 1;
        multiset<int> set;
        for(int r = 1; r < n; r++)
        {
            set.insert(a[r] - a[r - 1]);
            while(!set.empty() and *set.begin() < a[r])
            {
                set.erase(set.begin());
            }
            ans = max(ans, (int)set.size() + 1);
        }
        cout << ans << '\n';
    }
}