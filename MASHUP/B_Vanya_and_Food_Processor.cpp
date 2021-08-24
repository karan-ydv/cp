#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h, k;    cin >> n >> h >> k;
    int a[n];   for(int &x: a)  cin >> x;
    int sum = 0, ans = 0, i = 0;

    while(1)
    {
        while(i < n and sum + a[i] <= h)  sum += a[i++];
        if(i == n)  break;
        int m = (a[i] - h + sum) / k;
        sum -= k * m;
        ans += m;
        if(sum + a[i] > h)
        {
            sum -= min(sum, k);
            ans ++;
        }
    }
    ans += (sum + k - 1) / k;
    cout << ans;
}