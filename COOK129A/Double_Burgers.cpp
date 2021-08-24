#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 64;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int x, y;   cin >> x >> y;
        if(y % x != 0)
        {
            cout << "-1\n";
            continue;
        }
        int z = y / x;
        int ans = 1e18;
        for(int i = 1; i < N; i++)
        {
            int s = z + i;
            if(s & 1)   continue;
            bitset<N> b(s);
            if(b.count() != i)  continue;
            int c = 0;
            for(int i = 1; i < N; i++)
            {
                if(b[i])    c += i;
            }
            // cerr << b.to_string() << endl;
            ans = min(ans, c + i - 1);
        }
        if(ans == 1e18) ans = -1;
        // cerr << '\n';
        cout << ans << '\n';
    }
}