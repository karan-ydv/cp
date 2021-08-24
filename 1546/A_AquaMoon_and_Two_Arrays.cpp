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
        int a[n];   for(int &x: a)  cin >> x;
        int b[n];   for(int &x: b)  cin >> x;

        if(accumulate(a, a + n, 0ll) != accumulate(b, b + n, 0ll))
        {
            cout << "-1\n";
            continue;
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            while(a[i] < b[i])
            {
                for(int j = i + 1; j < n; j++) {
                    if(a[j] > b[j] and a[i] < b[i])
                    {
                        ans.emplace_back(j + 1, i + 1);
                        a[i] += 1, a[j] -= 1;
                    }
                }
            }
            while(a[i] > b[i])
            {
                for(int j = i + 1; j < n; j++) {
                    if(a[j] < b[j] and a[i] > b[i])
                    {
                        ans.emplace_back(i + 1, j + 1);
                        a[i] -= 1, a[j] += 1;
                    }
                }
            }
        }
        // for(int x: a)   cerr << x << ' '; cerr << '\n';
        // for(int x: b)   cerr << x << ' '; cerr << '\n';
        cout << ans.size() << '\n';
        for(auto [i, j]: ans)   cout << i << ' ' << j << '\n';
    }
}