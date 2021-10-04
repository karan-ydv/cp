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
        int n;	cin >> n;
        int a[n]; for(int &x: a)    cin >> x;
        vector<tuple<int, int, int>> ans;
        for(int i = 0; i < n; i++) {
            int j = min_element(a + i, a + n) - a;
            if(j == i)  continue;
            ans.emplace_back(i + 1, j + 1, j - i);
            while(j > i)
            {
                swap(a[j], a[j - 1]);
                j--;
            }
        }
        cout << ans.size() << '\n';
        for(auto [a, b, c]: ans)
            cout << a << ' ' << b << ' ' << c << '\n';
    }
}