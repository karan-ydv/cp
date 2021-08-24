#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x: a)  cin >> x;
    int ans = k;
    if(a[k - 1] <= 0)
        for(int i = k - 1; i >= 0 and a[i] <= 0; i--) ans--;
    else
        for(int i = k; i < n and a[i] == a[k - 1]; i++) ans++;
    cout << ans;
}