#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a = (n + 1) % mod;
    int b = (n + 2) % mod;
    int ans = a * b % mod;
    cout << ans;
}