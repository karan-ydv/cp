#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5+69;
int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;   cin >> n >> x;
    n += 1;
    for(int i = 1; i < n; i++)
        cin >> a[i];
    partial_sum(a, a + n, a);
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += binary_search(a + i, a + n, a[i] + x);
    cout << ans;
}