#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        int a[n];   for(int &x: a)  cin >> x;
        int mx = *max_element(a, a + n), ans = 0;
        for(int L = 0; L + k - 1 < n; L++)
        {
            if(a[L + k - 1] == mx)
                ans += n - L - k + 1;
        }
        cout << ans << '\n';
    }
}