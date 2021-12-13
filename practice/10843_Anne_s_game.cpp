#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 2000000011;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int n;  cin >> n;
        int ans = 1;
        for(int i = 2; i < n; i++)
            (ans *= n) %= mod;
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}