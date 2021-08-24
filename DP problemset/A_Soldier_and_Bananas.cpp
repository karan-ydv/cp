#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n, w;
    cin >> k >> n >> w;
    int sum = k * w * (w + 1) / 2;
    cout << max(0ll, sum - n);
}