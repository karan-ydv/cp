#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+69;
int A[N], q, x, mex;
int modexp(int a, int n) {
    int p = 1;
    for(; n; n >>= 1, (a *= a) %= mod)
        if(n & 1)   (p *= a) %= mod;
    return p;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q >> x;
    while(q--)
    {
        int v;  cin >> v;
        A[v % x]++;
        while(A[mex % x])
        {
            A[mex % x]--;
            mex++;
        }
        cout << mex << '\n';
    }
}