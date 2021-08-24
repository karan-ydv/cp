#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+5;
int A[N];
int pmax[N], pmin[N];
int smax[N], smin[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    if(p >= 0 and q >= 0 and r >= 0)
    {
        int mx = *max_element(A + 1, A + n + 1);
        int ans = mx * (p + q  + r);
        return cout << ans, 0;
    }
    if(p <= 0 and q <= 0 and r <= 0)
    {
        int mn = *min_element(A + 1, A + n + 1);
        int ans = mn * (p + q  + r);
        return cout << ans, 0;
    }

    pmax[0] = smax[n + 1] = -1e18;
    pmin[0] = smin[n + 1] = 1e18;
    for(int i = 1; i <= n; i++)
    {
        pmax[i] = max(A[i], pmax[i - 1]);
        pmin[i] = min(A[i], pmin[i - 1]);
    }
    for(int i = n; i >= 1; i--)
    {
        smax[i] = max(A[i], smax[i + 1]);
        smin[i] = min(A[i], smin[i + 1]);
    }
    
    int ans = LLONG_MIN;
    cerr << ans;
    for(int i = 1; i <= n; i++)
    {
        int x = q * A[i];
        x += p * (p < 0 ? pmin[i] : pmax[i]);
        x += r * (r < 0 ? smin[i] : smax[i]);
        ans = max(ans, x);
    }
    cout << ans;
}