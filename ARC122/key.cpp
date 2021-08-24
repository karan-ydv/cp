#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + n], ans[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    if (k < 0)
    {
        int sum = 0;
        for (int i = n + k; i < n; i++)
            sum += a[i];
        for (int i = n; i < n + n; i++)
        {
            ans[i - n] = sum;
            sum += a[i];
            sum -= a[i + k];
        }
    }
    else
    {
        int sum = 0;
        for (int i = 1; i < k; i++)
            sum += a[i];
        for (int i = 0; i < n; i++)
        {
            sum += a[i + k];
            ans[i] = sum;
            sum -= a[i + 1];
        }
    }
    for (int x : ans)
        cout << x << ' ';
}