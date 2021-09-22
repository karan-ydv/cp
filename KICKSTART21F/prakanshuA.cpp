#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    sort(a, a + n);
    long long ans = 1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] <= i)
        {
            ans = 0;
            break;
        }
        (ans *= a[i] - i) %= mod;
    }
    cout << ans << '\n';
}