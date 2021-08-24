#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int ans = 0;
        int n;  cin >> n;
        n <<= 1;
        for(int i = 1; i <= sqrt(n); i++)
        if(n % i == 0)
        {
            int x = n / i;
            x = x - i + 1;
            if(x > 0 and x % 2 == 0)
                ans++;
        }
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}