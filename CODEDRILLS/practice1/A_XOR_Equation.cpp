#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, x;   cin >> s >> x;
    if((s - x) & 1)
        return cout << '0', 0;
    int z = s - x >> 1, cnt = 0;
    for(int b = 1; b <= s; b <<= 1)
    if(z & b)
    {
        if(x & b)
            return cout << '0', 0;
    }
    int ans = (1LL << __builtin_popcountll(x));
    if(!(x & (x + 1)) and x != 0)
        ans -= 2;
    cout << ans;
}