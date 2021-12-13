#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int lcm(int a, int b) {
    int g = __gcd(a, b);
    return a * b / g;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m)
    {
        int a[m]; for(int &x: a) cin >> x;
        int ans = n;
        for(int i = 1; i < (1 << m); i++) {
            int c = 0, g = 1;
            for(int j = 0, b = 1; b <= i and g <= n; j++, b <<= 1) {
                if(i & b) g = lcm(g, a[j]), c++;
            }
            if(c & 1)
                ans -= n / g;
            else
                ans += n / g;
        }
        cout << ans << '\n';
    }
}