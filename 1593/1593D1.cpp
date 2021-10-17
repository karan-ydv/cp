#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solve()
{
    int n;	cin >> n;
    int a[n]; for(int &x: a)    cin >> x;
    if(all_of(a, a + n, [&](int x) {return x == a[0];} )) {
        return -1;
    }
    int mn = *min_element(a, a + n);
    for(int &x: a)  x -= mn;
    int mx = *max_element(a, a + n);

    for(int k = mx; k > 0; k--)
    {
        int x = a[0] % k, i;
        for(i = 1; i < n; i++)
            if(a[i] % k != x)  break;
        if(i == n)  return k;
    }
    return -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
}