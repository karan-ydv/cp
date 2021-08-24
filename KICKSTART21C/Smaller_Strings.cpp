#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n){
    int p = 1;
    while(n)
    {
        if(n & 1)	p = p * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return p;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        string s;
        int n, k;   cin >> n >> k >> s;
        int l = (n + 1) / 2;

        int ans = 0;
        for(int i = 0; i < l; i++)
        {
            if(s[i] != 'a')
            {
                if(s[i] > 'a' + k - 1)  (ans += k * modexp(k, l - i - 1) % mod) %= mod;
                else                    (ans += (s[i] - 'a') * modexp(k, l - i - 1) % mod) %= mod;
            }
        }
        // cerr << l << endl;
        string t = s.substr(0, l);
        reverse(t.begin(), t.end());
        if(n & 1)
            t = s.substr(0, l - 1) + t;
        else
            t = s.substr(0, l) + t;
        // cerr << t << endl;
        if(t < s)
            (ans += 1) %= mod;
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}