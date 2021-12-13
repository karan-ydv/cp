#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;   cin >> a >> b;
    int ans = 1e9;
    for(int i = 0, x = 1; a % x == 0; i++, x *= 2)
    for(int j = 0, y = 1; a % y == 0; j++, y *= 3)
    for(int k = 0, z = 1; a % z == 0; k++, z *= 5)
    for(int d = 0, p = 1; b % p == 0; d++, p *= 2)
    for(int e = 0, q = 1; b % q == 0; e++, q *= 3)
    for(int f = 0, r = 1; b % r == 0; f++, r *= 5)
        if(a / (x * y * z) == b / (p * q * r))
            ans = min(ans, i + j + k + d + e + f);

    if(ans == (int)1e9)
        ans = -1;
    cout << ans;
}