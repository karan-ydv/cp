#include <bits/stdc++.h>
#define int int64_t
using namespace std;

pair<int, int> f1(int i, int p)
{
    if(p < i)   return {0, 0};
    int beg = 0, end = 2e9, c;
    while(beg <= end)
    {
        int mid = beg + end >> 1;
        if((mid + 1) * (mid + i) <= p)
            c = mid, beg = mid + 1;
        else
            end = mid - 1;
    }
    // cerr << i << ' ' << p << " : ";
    // cerr << c + 1 << ' ' << (c + 1) * (c + i) << '\n';
    return {c + 1, (c + 1) * (c + i)};
}
int f2(int d)
{
    int beg = 0, end = 2e9, ans;
    while(beg <= end)
    {
        int mid = beg + end >> 1;
        if(mid * (mid + 1) / 2 <= d)
            ans = mid, beg = mid + 1;
        else
            end = mid - 1;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int ans = 0;
        int L, R;   cin >> L >> R;
        int d = abs(R - L);
        int x = f2(d);
        ans += x;
        x++;
        if(R > L)   R -= x * (x - 1) / 2;
        else        L -= x * (x - 1) / 2;
        // cerr << ans << ' ' << L << ' '<< R << '\n';
        if(R > L)
        {
            auto [n, sum] = f1(x, R);
            ans += n, R -= sum;
            tie(n, sum) = f1(x + 1, L);
            ans += n, L -= sum;
        }
        else
        {
            auto [n, sum] = f1(x, L);
            ans += n, L -= sum;
            tie(n, sum) = f1(x + 1, R);
            ans += n, R -= sum;
        }
        cout << "Case #" << _ << ": " << ans << ' ' << L << ' ' << R << '\n';
    }
}