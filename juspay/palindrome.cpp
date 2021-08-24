#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int64_t> v;
    v.reserve((1 << 18));
    v.emplace_back(-1);
    v.emplace_back(0);
    for(unsigned int i = 1; i <= 16; i++)
    {
        for(unsigned int x = 1; x < (1u << i); x += 2)
        {
            bitset<32> b(x), c = b;
            for(int j = 0; j < i; j++)
            {
                b[2 * i - j - 1] = b[j];
                c[2 * i - j - 2] = c[j];
            }
            v.emplace_back(b.to_ullong());
            v.emplace_back(c.to_ullong());
        }
    }
    sort(v.begin(), v.end());
    int t;	cin >> t;
    while(t--)
    {
        typedef int int64_t;
        int n, ans;	cin >> n;
        auto x = lower_bound(v.begin(), v.end(), n);
        ans = *x - n;
        ans = min(ans, int(n - *--x));
        cout << ans << '\n';
    }
}