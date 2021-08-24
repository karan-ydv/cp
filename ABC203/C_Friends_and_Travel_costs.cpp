#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;   cin >> n >> k;
    pair<int, int> a[n];
    for(auto &[x, y]: a)    cin >> x >> y;
    sort(a, a + n);

    int i = 0, j = 0;
    while(k > 0)
    {
        i += k;
        k = 0;
        while(j < n and a[j].first <= i)
            k += a[j++].second;
    }
    cout << i;
}