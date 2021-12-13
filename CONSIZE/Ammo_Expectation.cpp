#include <bits/stdc++.h>
#define L long long
using namespace std;

L n, k, c, i, p, j, g, y;
const L N = 1e6+1;
long double f[N], z;

int main()
{
    f[1] = 1;

    for (i = 1; ++i < N and (f[i] += i - 1); )
        for ( j = 2 * i; j < N; j += i)
              f[j] -= f[i];

    cin >> n >> k;
    L a[n]; for(L &x: a)    cin >> x, y = x;

    for(L x: a)
    {
        g = gcd(x, y);
        z += g * f[x] * f[y] / f[g] / x / y;
        y = x;
    }

    printf("%.9Lf", 2 * k * z);
}