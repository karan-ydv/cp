#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;	cin >> n;
    int a[n], b[n];
    for(int &x: a)  cin >> x;
    for(int &x: b)  cin >> x;

    int sum = 0;
    for(int i = 0; i < n; i++)  sum += a[i] * b[i];

    int ans = sum;
    for(int i = 0; i < n; i++) 
    {
        int curr = sum;
        for(int l = i - 1, r = i + 1; l >= 0 and r < n; l--, r++) 
        {
            curr += a[l] * b[r] + a[r] * b[l];
            curr -= a[l] * b[l] + a[r] * b[r];
            ans = max(ans, curr);
        }
    }
    for(int i = 0; i < n; i++) 
    {
        int curr = sum;
        for(int l = i, r = i + 1; l >= 0 and r < n; l--, r++) 
        {
            curr += a[l] * b[r] + a[r] * b[l];
            curr -= a[l] * b[l] + a[r] * b[r];
            ans = max(ans, curr);
        }
    }
    cout << ans;
}