#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;   cin >> n >> k;
    int ans = 0;
    for(int i = 100; i <= n * 100; i += 100)
        for(int j = i + 1; j <= i + k; j++)
            ans += j;
    cout << ans;
}