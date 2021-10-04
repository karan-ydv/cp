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
        int a[n];   for(int &x: a)  cin >> x, x = -x;
        sort(a, a + n);
        cout << upper_bound(a, a + n, a[k - 1]) - a << '\n';
    }
}