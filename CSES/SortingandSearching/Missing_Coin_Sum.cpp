#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5+69;
int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > ans) break;
        ans += a[i];
    }
    cout << ans;
}