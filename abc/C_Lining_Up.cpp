#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n; int f[n]{};
    for(int i = 1; i <= n; i++) {
        f[abs(i - 1 - n + i)]++;
        int x; cin >> x; f[x]--;
    }

    for(int x: f)   if(x)   return cout << "0", 0;
    int ans = 1;
    for(int i = 0; i < n / 2; i++)
        (ans *= 2) %= mod;
    cout << ans;
}