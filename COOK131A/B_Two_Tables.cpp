#include <bits/stdc++.h>
#define int int64_t
using namespace std;

double solve()
{
    double W, H;   cin >> W >> H;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double w, h; cin >> w >> h;

    double L = x2 - x1, B = y2 - y1;
    // cerr << w + (x2 - x1) << ' ' << h + (y2 - y1) << endl;
    if(w + (x2 - x1) > W and h + (y2 - y1) > H)
        return -1;

    double ans = 1e18;
    double a, b, c, d;

    c = w, d = h;
    if(c <= x1 or d <= y1)
        return 0;
    
    if(w + L <= W)
    ans = min(ans, w - x1);
    if(h + B <= H)
    ans = min(ans, h - y1);

    a = x2, b = y1;
    c = W - w, d = h;

    if(a <= c or d <= b)
        return 0;
    
    if(w + L <= W)
    ans = min(ans, a - c);
    if(h + B <= H)
    ans = min(ans, d - b);

    a = W - w, b = H - h;
    if(x2 <= a or y2 <= b)
        return 0;
    if(w + L <= W)
    ans = min(ans, x2 - a);
    if(h + B <= H)
    ans = min(ans, y2 - b);

    a = w, b = H - h;
    c = x1, d = y2;
    
    if(a <= c or d <= b)
        return 0;
    
    if(w + L <= W)
    ans = min(ans, a - c);
    if(h + B <= H)
    ans = min(ans, d - b);

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    cout << fixed << setprecision(12);
    while(t--)
    {
        cout << solve() << '\n';
    }
}