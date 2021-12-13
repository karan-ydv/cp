#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int fun(int a[], int n)
{
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        x += abs(a[i] - a[n / 2]);
        y += abs(a[i] - a[(n - 1) / 2]);
    }
    return min(x, y);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n; int a[n];
        for(int &x: a)  cin >> x;
        sort(a, a + n);
        int ans = min(fun(a, n - 1), fun(a + 1, n - 1));
        for(int l = 1, r = n - 2; l < r; )
        {
            int x = a[r] - a[0];
            int y = a[n - 1] - a[l];
            if(x < y)
                ans = min(ans, y - x), l++;
            else
                ans = min(ans, x - y), r--;
        }
        cout << ans << '\n';
    }
}