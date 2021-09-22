#include <bits/stdc++.h>
// #include <sys/resource.h>
#define int int64_t
using namespace std;

#define pii pair<int, int>

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // rlimit R;
    // getrlimit(RLIMIT_STACK, &R);
    // R.rlim_cur = R.rlim_max;
    // setrlimit(RLIMIT_STACK, &R);
    int t;	cin >> t;
    while(t--)
    {
        int n, k, x;    cin >> n >> k >> x;
        int a[n];   for(int &x: a)  cin >> x;
        pair<int, int> p[n];
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += a[i];
            p[i] = {a[i], i};
        }
        partial_sort(p, p + 2 * k, p + n, greater<pii>());
        for(int i = 0; i < 2 * k; i += 2)
        {
            if(p[i].first + p[i + 1].first > x)
            ans += x - p[i].first - p[i + 1].first;
        }
        cout << ans << '\n';
    }
}