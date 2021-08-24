#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n];
    int sum = 0, mn = 2e9, cnt = 0;
    for(int &x: a)  cin >> x, sum += abs(x), mn = min(mn, abs(x)), cnt += x < 0;
    if(find(a, a + n, 0ll) != a + n)
        return cout << sum, 0;
    if(cnt & 1) sum -= mn << 1;
    cout << sum;
}