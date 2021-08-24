#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int sumOfAP(int a, int d, int n)
{
    return  n * a + n * (n - 1) * d / 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int D, d, P, Q;
        cin >> D >> d >> P >> Q;
        int ans = sumOfAP(P, Q, D / d) * d;
        ans += D % d * (P + D / d * Q);
        cout << ans << '\n';
    }
}