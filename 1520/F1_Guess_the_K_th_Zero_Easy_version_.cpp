#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int cnt = 0;
int query(int l, int r)
{
    assert(cnt < 20);
    ++cnt;
    cout << "? " << l << ' ' << r << endl;
    int x;  cin >> x;
    assert(x != -1);
    return x;
}
void output(int ans)
{
    cout << "! " << ans << endl;
    int x;  cin >> x;
    assert(x != -1);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;	cin >> n >> t;
    while(t--)
    {
        int k;	cin >> k;
        int beg = 1, end = n, ans;
        cnt = 0;
        while(beg <= end)
        {
            int mid = (beg + end) >> 1;
            int x = mid - query(1, mid);
            if(x >= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else    beg = mid + 1;
        }
        output(ans);
    }
}