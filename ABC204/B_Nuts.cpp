#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x;  cin >> x;
        ans += max(0ll, x - 10);
    }
    cout << ans;
}