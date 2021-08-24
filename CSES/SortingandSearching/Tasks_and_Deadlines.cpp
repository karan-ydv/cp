#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5+69;
int a[N], n, sum;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        int x;  cin >> x;
        sum += x;
    }
    sort(a, a + n);
    partial_sum(a, a + n, a);
    sum -= accumulate(a, a + n, 0ll);
    cout << sum;
}