#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+69;
int A[N], pref[N];
int n;

double fun(int x)
{
    double ret = pref[n] + x * n / 2.0;
    int i = upper_bound(A + 1, A + n + 1, x) - A - 1;
    return ret - pref[i] - x * (n - i);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    
    sort(A + 1, A + n + 1);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + A[i];

    double ans = 1e18;
    for(int i = 1; i<= n; i++)
        ans = min(ans, fun(A[i]));
    
    ans /= n;
    cout << setprecision(20) << ans;
}