#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    while(cin >> n >> t, n and t)
    {
        int a[n]; for(int &x: a)    cin >> x;
        for(int i = 0; i < t; i++) {
            int len; cin >> len;
            int mn = 1e9, mx = -1e9;
            string s = string(n - 4, '0') + "1111";
            do
            {
                int l = 1;
                for(int i = 0; i < n; i++)
                    if(s[i] == '1') l = lcm(l, a[i]);
                int x = len - len % l, y = len + (l - len % l) % l;
                mx = max(mx, x);
                mn = min(mn, y);
            } while(next_permutation(s.begin(), s.end()));
            cout << mx << ' ' << mn << '\n';
        }
    }
}