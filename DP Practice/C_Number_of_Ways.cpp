#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    int sum = accumulate(a, a + n, 0ll);
    if(sum % 3) return cout << "0", 0;
    int psum = 0, ssum = 0;
    int cnt = 0;
    for(int i = n - 1; i > 0; i--) {
        ssum += a[i];
        cnt += 3 * ssum == sum;
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        cnt -= 3 * ssum == sum;
        ssum -= a[i + 1];
        psum += a[i];
        if(3 * psum == sum) ans += cnt;
    }
    cout << ans;
}