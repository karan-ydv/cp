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
        int n, even = 0, odd = 0;   cin >> n;
        int a[n];   for(int &x: a)  cin >> x, odd += x & 1, even += !(x & 1);
        int ans = min(odd, n / 2) + min(even, n - n / 2);
        cout << ans << '\n';
    }
}