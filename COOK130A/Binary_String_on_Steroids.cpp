#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s;
        int n;	cin >> n >> s;
        s = "!" + s + s;
        int pref[n + n + 2] = {};
        for(int i = 1; i <= n + n; i++) {
            pref[i] = pref[i - 1] + (s[i] - '0');
        }
        int ans = 1e9;
        auto fun = [&](int d)
        {
            for(int j = 1; j <= d; j++)
            {
                int cnt = 0;
                for(int k = j; k <= n; k += d)
                {
                    cnt += s[k] == '0';
                    cnt += pref[k + d - 1] - pref[k];
                }
                ans = min(ans, cnt);
            }
        };
        for(int i = 1; i <= sqrt(n); i++)
        if(n % i == 0)
        {
            fun(i);
            fun(n / i);
        }
        cout << ans << '\n';        
    }
}