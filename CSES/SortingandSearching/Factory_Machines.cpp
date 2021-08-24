#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;   cin >> n >> t;
    int a[n];   for(int &x: a)  cin >> x;
    sort(a, a + n);
    auto possible = [&](int x)
    {
        int cnt = 0;
        for(int i = 0; i < n and a[i] <= x and cnt < t; i++) {
            cnt += x / a[i];
        }
        return cnt >= t;
    };
    int beg = 0, end = 1e18, ans;
    while(beg <= end)
    {
        int mid = beg + end >> 1;
        if(possible(mid))
            ans = mid, end = mid - 1;
        else
            beg = mid + 1;
    }
    cout << ans;
}