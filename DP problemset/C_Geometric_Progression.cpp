#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> pref, suff;
    int a[n];
    for (int &x : a)
        cin >> x, suff[x]++;
    int ans = 0;
    suff[a[0]]--;
    for (int i = 1; i < n - 1; i++)
    {
        pref[a[i - 1]]++;
        suff[a[i]]--;
        if (a[i] % k == 0 and pref.count(a[i] / k) and suff.count(a[i] * k))
            ans += pref[a[i] / k] * suff[a[i] * k];
    }
    cout << ans;
}