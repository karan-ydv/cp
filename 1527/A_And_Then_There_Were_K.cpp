#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int msbPos(int n)
{
    int msb_p = -1;
    while (n)
    {
        n = n >> 1;
        msb_p++;
    }
    return msb_p;
}
int andOperator(int x, int y)
{
    int res = 0;
    while (x && y)
    {
        int msb_p1 = msbPos(x);
        int msb_p2 = msbPos(y);
        if (msb_p1 != msb_p2)
            break;
        int msb_val = (1 << msb_p1);
        res = res + msb_val;
        x = x - msb_val;
        y = y - msb_val;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int beg = 1, end = n, ans = 0;
        while (end >= beg)
        {
            int mid = beg + end >> 1;
            if (andOperator(mid, n) == 0)
                beg = mid + 1, ans = mid;
            else
                end = mid - 1;
        }
        cout << ans << '\n';
    }
}