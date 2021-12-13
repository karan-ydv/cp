#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5+5;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int a, b;   cin >> a >> b;
        bitset<N> ans;
        int p = (a + b) / 2;
        int q = (a + b + 1) / 2;
        for(int x = 0; x <= p; x++) {
            int y = a - p + x;
            if(y < 0 or y > q)  continue;
            ans[x + y] = 1;
        }
        swap(p, q);
        for(int x = 0; x <= p; x++) {
            int y = a - p + x;
            if(y < 0 or y > q)  continue;
            ans[x + y] = 1;
        }

        cout << ans.count() << '\n';
        for(int i = 0; i <= a + b; i++)
            if(ans[i])  cout << i << ' ';
        cout << '\n';
    }
}