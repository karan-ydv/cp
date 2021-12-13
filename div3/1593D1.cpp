#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solve()
{
    int n;	cin >> n;
    int a[n]; for(int &x: a)    cin >> x;
    if(all_of(a, a + n, [&](int x) {return x == a[0];} )) {
        return -1;
    }
    int mn = *min_element(a, a + n);
    int ans = 0;
    for(int x: a)   ans = gcd(ans, x - mn);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
}