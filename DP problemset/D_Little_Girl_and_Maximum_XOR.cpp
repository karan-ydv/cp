#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    if(l == r)  return cout << "0", 0;
    int b = 1LL << 62;
    while(1)
    {
        if((l & b) != (r & b))
        {
            b |= b - 1;
            return cout << b, 0;
        }
        b >>= 1;
    }
}